///
/// \file VoltageDividerWidget.cpp
/// \date 30.11.2016
/// \author Michael Trummer
///

#include "VoltageDividerWidget.h"
#include <QDebug>
#include <cmath>
#include "ui_voltagedividerwidget.h"

VoltageDividerWidget::VoltageDividerWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Form),
      validateU1(new UserInputValidator("V", this)),
      validateU2(new UserInputValidator("V", this)),
      validateRmin(new UserInputValidator("Ohm", this)),
      validateRmax(new UserInputValidator("Ohm", this)), u1(0), u2(0), vOut(0)
{
  ui->setupUi(this);
  ui->label_5->setAttribute(Qt::WA_TranslucentBackground);

  ui->lineEditU1->setValidator(validateU1);
  ui->lineEditU2->setValidator(validateU2);
  ui->lineEditRmin->setValidator(validateRmin);
  ui->lineEditRmax->setValidator(validateRmax);

  connect(ui->pushButton, &QPushButton::clicked, this,
          &VoltageDividerWidget::onCalcRequest);
  connect(ui->lineEditU2, &QLineEdit::editingFinished, this,
          &VoltageDividerWidget::onCalcRequest);
  connect(ui->lineEditU1, &QLineEdit::editingFinished, this,
          &VoltageDividerWidget::onCalcRequest);
  connect(ui->lineEditRmin, &QLineEdit::editingFinished, this,
          &VoltageDividerWidget::onCalcRequest);
  connect(ui->lineEditRmax, &QLineEdit::editingFinished, this,
          &VoltageDividerWidget::onCalcRequest);
  connect(ui->comboBox, static_cast<void (QComboBox::*)(int)>(
                            &QComboBox::currentIndexChanged),
          this, &VoltageDividerWidget::onCalcRequest);

  IESeries::SeriesType serieType = IESeries::e12;
  for (unsigned int i = 0; i < IESeries::nrOfESeries; ++i)
  {
    ESeries serie(serieType);
    ui->comboBox->addItem(serie.getName().c_str());
    ++serieType;
  }

  ui->comboBox->setCurrentIndex(IESeries::e24);
  ui->lineEditRmin->setText("1k Ohm");
  ui->lineEditRmax->setText("10k Ohm");
}

VoltageDividerWidget::~VoltageDividerWidget()
{
  delete ui;
  delete validateU1;
}

void VoltageDividerWidget::onCalcRequest()
{
  if (!validateU1->getIsValid())
  {
    clearResult();
    return;
  }
  if (!validateU2->getIsValid())
  {
    clearResult();
    return;
  }
  if (!validateRmin->getIsValid())
  {
    clearResult();
    return;
  }
  if (!validateRmax->getIsValid())
  {
    clearResult();
    return;
  }

  u1 = validateU1->getValue();
  u2 = validateU2->getValue();

  if (u1 <= u2)
  {
    clearResult();
    return;
  }
  if (0 == u2)
  {
    clearResult();
    return;
  }

  IESeries::SeriesType serieType;
  switch (ui->comboBox->currentIndex())
  {
    default:
    case IESeries::e12:
      serieType = IESeries::e12;
      break;
    case IESeries::e24:
      serieType = IESeries::e24;
      break;
  }

  EResistor rMin(validateRmin->getValue(), EResistor::assignUpperEValue,
                 ESeries(serieType));
  EResistor rMax(validateRmax->getValue(), EResistor::assignLowerEValue,
                 ESeries(serieType));

  if (rMin >= rMax)
  {
    clearResult();
    return;
  }

  disconnect(ui->lineEditU2, &QLineEdit::editingFinished, this,
             &VoltageDividerWidget::onCalcRequest);
  disconnect(ui->lineEditU1, &QLineEdit::editingFinished, this,
             &VoltageDividerWidget::onCalcRequest);
  disconnect(ui->lineEditRmin, &QLineEdit::editingFinished, this,
             &VoltageDividerWidget::onCalcRequest);
  disconnect(ui->lineEditRmax, &QLineEdit::editingFinished, this,
             &VoltageDividerWidget::onCalcRequest);

  VoltageDivider::ResultingResistors resResistors =
      VoltageDivider::calc(u1, u2, rMin, rMax);

  onResultRefresh(resResistors.r1, resResistors.r2);

  if (!ui->lineEditU1->text().contains("V", Qt::CaseInsensitive))
    ui->lineEditU1->setText(ui->lineEditU1->text() + " V");
  if (!ui->lineEditU2->text().contains("V", Qt::CaseInsensitive))
    ui->lineEditU2->setText(ui->lineEditU2->text() + " V");
  if (!ui->lineEditRmin->text().contains("Ohm", Qt::CaseInsensitive))
    ui->lineEditRmin->setText(ui->lineEditRmin->text() + " Ohm");
  if (!ui->lineEditRmax->text().contains("Ohm", Qt::CaseInsensitive))
    ui->lineEditRmax->setText(ui->lineEditRmax->text() + " Ohm");

  connect(ui->lineEditU2, &QLineEdit::editingFinished, this,
          &VoltageDividerWidget::onCalcRequest);
  connect(ui->lineEditU1, &QLineEdit::editingFinished, this,
          &VoltageDividerWidget::onCalcRequest);
  connect(ui->lineEditRmin, &QLineEdit::editingFinished, this,
          &VoltageDividerWidget::onCalcRequest);
  connect(ui->lineEditRmax, &QLineEdit::editingFinished, this,
          &VoltageDividerWidget::onCalcRequest);

  assert(vOut < u1);
}

void VoltageDividerWidget::clearResult()
{
  ui->lineEditR1->setText("");
  ui->lineEditR2->setText("");
  ui->lineEditVout->setText("");
  ui->lineEditAccuracy->setText("");
}

void VoltageDividerWidget::onResultRefresh(double r1, double r2)
{
  ui->lineEditR1->setText(QString::number(r1, 'g') + " Ohm");
  ui->lineEditR2->setText(QString::number(r2, 'g') + " Ohm");
  vOut = u1 * r2 / (r1 + r2);
  ui->lineEditVout->setText(QString::number(vOut, 'g', 3) + " V");
  ui->lineEditAccuracy->setText(
      QString::number(std::abs(100 - vOut * 100 / u2), 'g', 3) + "%");
}
