///
/// \file main.cpp
/// \date 30.11.2016
/// \author Michael Trummer
///

#include <QApplication>
#include "VoltageDividerWidget.h"
#include "VoltageDivider.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  VoltageDividerWidget w;
  w.show();

  return a.exec();
}
