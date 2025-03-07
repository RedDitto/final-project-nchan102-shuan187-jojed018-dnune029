#include "gtest/gtest.h"
#include "task.hpp"
#include "tasklist.hpp"
#include "base.hpp"
#include <iostream>
#include "tasks.hpp"
#include "tasklistTests.h"
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

