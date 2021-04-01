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

void printLinkedNodes(ListNode* start_node)
{
        ListNode* node = start_node;
        std::cout << "==================" << "print nodes" << "==================" << std::endl;
        while(node != nullptr)
        {
            std::cout << "==================" << node->val << "==================" << std::endl;
            node = node->next;
        }
}

void DELETE_NODE(ListNode* node)
{
    if(node != nullptr)
    {
        delete node;
        node = nullptr;
    }
}