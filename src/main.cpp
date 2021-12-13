///
/// \file main.cpp
/// \date 30.11.2016
/// \author Michael Trummer
///

#include <QApplication>
#include "VoltageDividerWidget.h"
#include "VoltageDivider.h"
#include <iostream>
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  VoltageDividerWidget w;
  w.show();

  ::testing::InitGoogleTest(&argc, argv);
  std::cout << RUN_ALL_TESTS();

  return a.exec();
}
