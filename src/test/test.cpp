#include "../include/pantilt.hpp"
#include <stdlib.h>

#include <gtest/gtest.h>

#include <iostream>

using namespace std;
using namespace dianamessenger;

TEST(DianaMessenger, diagnostic)
{
  ASSERT_EQ(1 + 1, 2);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
