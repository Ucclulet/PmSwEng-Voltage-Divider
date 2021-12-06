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

  ///
  /// \brief Constructor which sets the variables values, elemCnt and name in 
  /// realtion to the defined serie
  /// \param serie is a enum of the type SeriesType
  ///
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

  ///
  /// \brief Gets the number of elements in the e-series
  /// \return returns the number of elements in the e-series
  ///
  
  unsigned int getElemCnt() const
  {
    return elemCnt;
  }

  ///
  /// \brief Gets the name of the e-series
  /// \return returns the name of the e-series
  ///
  
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
