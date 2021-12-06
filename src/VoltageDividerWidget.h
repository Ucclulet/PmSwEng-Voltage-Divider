///
/// \file VoltageDividerWidget.h
/// \date 30.11.2016
/// \author Michael Trummer
///

#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "ESeries.h"
#include "UserInputValidator.h"
#include "VoltageDivider.h"

namespace Ui
{
class Form;
}

///
/// \brief The VoltageDividerWidget class represents a widget with integrated
///        sub widgets for input and output. It uses the VoltageDivider class
///        to determine the output resistors in addiction to the voltage input
///        values.
///
class VoltageDividerWidget : public QWidget {
  Q_OBJECT

 public:
///
/// \brief Constructor of class VoltageDividerWidget
/// \param A parent QT window can be defined. Default is root.
///

  explicit VoltageDividerWidget(QWidget *parent = 0);

///
/// \brief This is the default destructor
///

  ~VoltageDividerWidget();

 public slots:
///
/// \brief Refeshes the window after the results are calculated
/// \param r1 Calculated result of Resistor 1
/// \param r2 Calculated result of Resistor 2
///

  void onResultRefresh(double r1, double r2);

 private:
  Ui::Form *ui;
  UserInputValidator *validateU1;
  UserInputValidator *validateU2;
  UserInputValidator *validateRmin;
  UserInputValidator *validateRmax;

  double u1;
  double u2;
  double vOut;

  void onNewU1Value();
  void onNewU2Value();
  void onNewRmaxValue();
  void onNewRminValue();
  void onCalcRequest();
  void onResistorDecadeChanged(int idx);
  void clearResult();
};

#endif  // FORM_H
