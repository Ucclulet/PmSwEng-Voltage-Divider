///
/// \file QValidator.cpp
/// \date 30.11.2016
/// \author Michael Trummer
///

#include "UserInputValidator.h"

UserInputValidator::UserInputValidator(const QString& unit, QObject* parent) :
  QValidator(parent),
  unit(unit),
  value(0.0),
  isValid(false)
{

}

///
/// \brief Validate the User-input to be valid values for the Formula.
///
/// \param &input User-input data
/// \param &pos 
/// \return returns QValidator::Acceptable if ok, otherwise QValidator::Intermediate
/// 
QValidator::State UserInputValidator::validate(QString &input, int &pos) const
{
  static_cast<void>(pos);  //suppress unused parameter compiler warning
  QString str = input;
  str.remove(unit, Qt::CaseInsensitive); //remove unit string

  double power = 1;
  if (str.contains('m', Qt::CaseSensitive))
  {
    power = 1e-3;
    str.remove('m');
  }
  else if (str.contains('k', Qt::CaseSensitive))
  {
    power = 1e3;
    str.remove('k');
  }
  else if (str.contains('K', Qt::CaseSensitive))
  {
    power = 1e3;
    str.remove('K');
  }
  else if (str.contains('M', Qt::CaseSensitive))
  {
    power = 1e6;
    str.remove('M');
  }

  value = str.toDouble(&isValid);
  value *= power;

  return isValid? QValidator::Acceptable: QValidator::Intermediate;
}
