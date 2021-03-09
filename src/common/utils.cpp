#include "common/utils.h"

std::vector<int> splitInt(int num)
{
    int num_before = num;
    int num_after = num;
    std::vector<int> num_pro;
    while(num_before !=0)
    {
        num_before/= 10;
        num_pro.push_back(num_after - num_before * 10);
        num_after = num_before;
    }
    return num_pro;
}