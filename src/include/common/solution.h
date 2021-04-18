#ifndef SOLUTION_H
#define SOLUTION_H
#include "common/utils.h"
#include <unordered_set>
#include <math.h>
#include <queue>
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

            // easy
            bool isPalindrome(ListNode* head);

            // normal 
            std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

            // normal
            std::vector<int> preorderTraversal(TreeNode* root);

            void preTraversal(TreeNode* root, std::vector<int>& data);

            // normal
            std::vector<int> inorderTraversal(TreeNode* root);
            
            void inTraversal(TreeNode* root, std::vector<int>& data);

            // normal
            std::vector<int> postorderTraversal(TreeNode* root);

            void postTraversal(TreeNode* root, std::vector<int>& data);

            // normal
            std::vector<std::vector<int>> levelOrder(TreeNode* root);

            // easy
            int maxDepth(TreeNode* root);

            // easy
            bool isSymmetric(TreeNode* root);

            bool check(TreeNode* p, TreeNode* q);

            // easy
            bool hasPathSum(TreeNode* root, int targetSum);
};
#endif