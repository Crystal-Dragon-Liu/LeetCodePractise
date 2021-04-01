#include "gtest/gtest.h"
#include "common/utils.h"
#include "common/solution.h"
class MyLinkedList;


// delete a node.
void DELETE_LISTNODE(ListNode* node)
{
    if(node != nullptr)
    {
        delete node;
        node = nullptr;
    }
}

/**
 * Test List:
 * 1. ensure the class MyLinkedList works well.
 * 2. make sure we could delete the n-to-last ListNode correctly.
 * 3. Given the head of a singly linked list, 
 *    group all the nodes with odd indices together followed by the nodes with even indices, 
 *    and return the reordered list.
 */

TEST(linkedListBasicTest, DISABLED_Test1)
{
    MyLinkedList linkedList;
    // insert data.
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2);
    linkedList.printNodes();
    
    std::cout << linkedList.get(1) << std::endl;

    linkedList.deleteAtIndex(1);
    std::cout << linkedList.get(1) << std::endl;
    linkedList.printNodes();
}



TEST(linkedListBasicTest, DISABLED_Test2)
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
    ListNode* result_node = solu.removeNthFromEnd(node_5, 1);
    printLinkedNodes(result_node);

    // release all of the nodes.
    DELETE_LISTNODE(node_5);
    DELETE_LISTNODE(node_4);
    DELETE_LISTNODE(node_3);
    DELETE_LISTNODE(node_2);
    DELETE_LISTNODE(node_1);
    DELETE_LISTNODE(node_0);
}



TEST(linkedListBasicTest, Test3)
{
    // initialize a singly-linked list
    ListNode* node_0 = new ListNode(6, nullptr);
    ListNode* node_1 = new ListNode(5, node_0);
    ListNode* node_2 = new ListNode(4, node_1);
    ListNode* node_3 = new ListNode(3, node_2);
    ListNode* node_4 = new ListNode(2, node_3);
    ListNode* node_5 = new ListNode(1, node_4);

    Solution solu;
    ListNode* result = solu.oddEvenList(node_5);
    printLinkedNodes(result);
    // release all of the nodes.
    DELETE_NODE(node_5);
    DELETE_NODE(node_4);
    DELETE_NODE(node_3);
    DELETE_NODE(node_2);
    DELETE_NODE(node_1);
    DELETE_NODE(node_0);
}