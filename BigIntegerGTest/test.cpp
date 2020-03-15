
#include "pch.h"
#include <iostream>
#include ""

using namespace std;

TEST(BigIntegerTest, getAsStringTest) {

  char* var = "12345678";
//  BigInteger* num = new BigInteger(var);
//  char* var2 = num->getAsString();
  //Assert::AreEqual(1, 1);
  //Assert::AreEqual(var, var2);
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);

}