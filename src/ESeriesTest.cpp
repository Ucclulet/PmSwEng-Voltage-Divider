#include <gtest/gtest.h>
#include "IESeries.h"
#include "ESeries.h"

TEST(VoltageDividerTest, test){
    EXPECT_EQ(1, 1);
}

TEST(ESeries, getNameTest){
   IESeries::SeriesType ser = IESeries::SeriesType::e12;
   ESeries es = *new ESeries(ser);

    EXPECT_EQ(es.getName(), "E12");
}
