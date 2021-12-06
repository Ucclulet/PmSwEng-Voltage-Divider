#ifndef IESERIES_H
#define IESERIES_H

#include <string>

///
/// \brief The IESeries class is an interface to be able to mock ESeries class
/// for test reasons.
///
class IESeries {
 public:

  enum SeriesType
  {
    e12 = 0,
    e24,
    nrOfESeries
  };

  
  friend SeriesType& operator++(SeriesType& serie);

  ///
  /// \brief Gets the number of elements in the e-series
  /// \return returns the number of elements in the e-series
  ///
  
  virtual unsigned int getElemCnt() const = 0;
  
  ///
  /// \brief Gets the name of the e-series
  /// \return returns the name of the e-series
  ///

  virtual std::string getName() const = 0;

  virtual double operator[](int index) const = 0;
};

#endif  // IESERIES_H
