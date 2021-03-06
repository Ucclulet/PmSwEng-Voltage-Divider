#ifndef ERESISTOR_H
#define ERESISTOR_H

#include <cmath>
#include "IESeries.h"

///
/// \brief An Object of the EResistor class represents a resistor of the
/// corresponding E series passed in Ctor.
/// series.
///
class EResistor {
 public:

  enum AssignMethod
  {
    assignUpperEValue,
    assignLowerEValue
  };

  ///
  /// \brief Constructor of the EResistor Class.
  /// \param value of the Resistor
  /// \param method choose if the Resistor has to be assigned to the lower or the higher E-Value
  /// \param serie Reference to actual set E Series
  ///
  EResistor(double value, AssignMethod method, const IESeries& serie);

  bool operator<(const EResistor& rhs) const
  {
    return getValue() < rhs.getValue();
  }

  bool operator<=(const EResistor& rhs) const
  {
    return getValue() <= rhs.getValue();
  }

  bool operator>(const EResistor& rhs) const
  {
    return getValue() > rhs.getValue();
  }

  bool operator>=(const EResistor& rhs) const
  {
    return getValue() >= rhs.getValue();
  }


  const EResistor& operator++()
  {
    if (++index >= eSerie.getElemCnt())
    {
      index = 0;
      exp++;
    }
    return *this;
  }

  double operator+(const EResistor& rhs)
  {
    double sum = getValue() + rhs.getValue();

    return sum;
  }

  double operator*(const EResistor& rhs)
  {
    double rhsVal = rhs.getValue();
    double val = getValue();
    return rhsVal * val;
  }

  operator double() const
  {
    return getValue();
  }
  ///
  /// \brief Get the value of the resistor.
  /// \return returns actual Resistor value as double (always a value of the actual set E Series)
  ///
  double getValue() const
  {
    return eSerie[index] * pow(10, exp);
  }
  ///
  /// \brief Get the actual setted E Series
  /// \return returns actual E Series const Reference of IESeries object \p eSerie
  ///
  const IESeries& getSerie() const
  {
    return eSerie;
  }

 private:
  unsigned int index;
  int exp;

  void setLowerOrEqValue(double value);
  void setUpperOrEqValue(double value);

  const IESeries& eSerie;
};

#endif  // ERESISTOR_H
