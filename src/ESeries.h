///
/// \file src/ESeries.h
/// \date 30.11.2016
/// \author Michael Trummer
///

#ifndef ESERIES_H
#define ESERIES_H

#include <QString>
#include <cassert>
#include "IESeries.h"

///
/// \brief The ESeries class represents the E resistor series E12 and E24. If
/// more E resistor series are required, this class can be appended.
///
class ESeries : public IESeries {
 public:

  ESeries(IESeries::SeriesType serie) : type(serie)
  {
    switch (serie)
    {
      case IESeries::e12:
        values = e12Values;
        elemCnt = 12;
        name = "E12";
        break;
      default:
      case IESeries::e24:
        values = e24Values;
        elemCnt = 24;
        name = "E24";
        break;
    }
  }

  unsigned int getElemCnt() const
  {
    return elemCnt;
  }

  std::string getName() const
  {
    return name;
  }

  double operator[](int index) const
  {
    assert(index < static_cast<int>(elemCnt));
    assert(index >= 0);
    return values[index];
  }

 private:
  const double* values;
  unsigned int elemCnt;
  std::string name;
  SeriesType type;
  static const double e12Values[];
  static const double e24Values[];
};
#endif  // ESERIES_H
