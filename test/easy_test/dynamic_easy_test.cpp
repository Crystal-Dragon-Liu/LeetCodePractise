#include "gtest/gtest.h"
#include "common/utils.h"
#include "common/solution.h"

TEST(DynamicEasyTest, Test1)
{
    Solution solu;
    int f = solu.fib(4);
    std::cout << f << std::endl;
}
