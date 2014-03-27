#include "../include/pantilt.hpp"
#include <stdlib.h>

#include <gtest/gtest.h>

#include <iostream>

using namespace std;
using namespace dianamessenger;

int globalArgc;
char** globalArgv;


TEST(DianaMessenger, diagnostic)
{
  ASSERT_EQ(1 + 1, 2);
  Pantilt pantilt(globalArgc, globalArgv, "pantilt_test");
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);

  globalArgc = argc;
  globalArgv = argv;

  return RUN_ALL_TESTS();
}

