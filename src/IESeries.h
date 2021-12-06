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

  virtual unsigned int getElemCnt() const = 0;

  virtual std::string getName() const = 0;

  virtual double operator[](int index) const = 0;
};

#endif  // IESERIES_H
