#include "gtest/gtest.h"
#include "common/utils.h"
#include "common/solution.h"


/*
** Test
** 1. make sure the "reverse" works well
** 2. remove the element.
** 3. Palindrome Linked List
*/

TEST(LinkedListEasyTest, DISABLED_Test1)
{
    // initialize a singly-linked list.
    ListNode* node_0 = new ListNode(6, nullptr);
    ListNode* node_1 = new ListNode(5, node_0);
    ListNode* node_2 = new ListNode(4, node_1);
    ListNode* node_3 = new ListNode(3, node_2);
    ListNode* node_4 = new ListNode(2, node_3);
    ListNode* node_5 = new ListNode(1, node_4);
    Solution solu;
    // printLinkedNodes(node_5);
    // delete the n-to-last ListNode ptr.
    printLinkedNodes(node_5);
    ListNode* result_node = solu.reverseList(node_5);
    printLinkedNodes(result_node);

    // release all of the nodes.
    DELETE_NODE(node_5);
    DELETE_NODE(node_4);
    DELETE_NODE(node_3);
    DELETE_NODE(node_2);
    DELETE_NODE(node_1);
    DELETE_NODE(node_0);
}


TEST(linkedListBasicTest, DISABLED_Test2)
{
     // initialize a singly-linked list.
    ListNode* node_0 = new ListNode(6, nullptr);
    ListNode* node_1 = new ListNode(5, node_0);
    ListNode* node_2 = new ListNode(3, node_1);
    ListNode* node_3 = new ListNode(3, node_2);
    ListNode* node_4 = new ListNode(2, node_3);
    ListNode* node_5 = new ListNode(1, node_4);
    Solution solu;
    ListNode* result =  solu.removeElements(node_5, 3);
    printLinkedNodes(result);
        // release all of the nodes.
    DELETE_NODE(node_5);
    DELETE_NODE(node_4);
    DELETE_NODE(node_3);
    DELETE_NODE(node_2);
    DELETE_NODE(node_1);
    DELETE_NODE(node_0);
}

TEST(linkedListBasicTest, Test3)
{
      // initialize a singly-linked list.
    ListNode* node_0 = new ListNode(1, nullptr);
    ListNode* node_1 = new ListNode(3, node_0);
    ListNode* node_2 = new ListNode(2, node_1);
    ListNode* node_3 = new ListNode(2, node_2);
    ListNode* node_4 = new ListNode(3, node_3);
    ListNode* node_5 = new ListNode(1, node_4);

    Solution solu;
    bool result = solu.isPalindrome(node_5);
    std::cout  << (result == true ? "true" : "false") << std::endl;

    DELETE_NODE(node_5);
    DELETE_NODE(node_4);
    DELETE_NODE(node_3);
    DELETE_NODE(node_2);
    DELETE_NODE(node_1);
    DELETE_NODE(node_0);
}