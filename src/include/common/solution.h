#ifndef SOLUTION_H
#define SOLUTION_H
#include "common/utils.h"
#include <unordered_set>
#include <math.h>
class Solution
{
    public:
            //easy
            bool hasCycle(ListNode* head);
            //normal
            ListNode *detectCycle(ListNode *head);

            //easy
            bool containsDuplicate(std::vector<int>& nums);
            
            //easy
            int singleNumber(std::vector<int>& nums);

            //easy
            std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2);
            std::vector<int> get_intersection(const std::unordered_set<int>& set1, const std::unordered_set<int>& set2);

            //easy
            bool isHappy(int n);
            int getNext(int n);

            //easy
            ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);

            //normal
            ListNode* removeNthFromEnd(ListNode* head, int n);

            // easy
            ListNode* reverseList(ListNode* head);

            // easy
            ListNode* removeElements(ListNode* head, int val);

            // normal
            ListNode* oddEvenList(ListNode* head);
};
#endif