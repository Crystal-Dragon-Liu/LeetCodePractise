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
 * 2. test the interface "addAtHead"
 * 3. test the interface "addAtTail"
 * 4. test the interface "addAtIndex"
 * 5. test the interface "get"
 * 6. test the interface "deleteAtIndex"
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


/*
** make sure we could delete the n-to-last ListNode correctly.
*/
TEST(linkedListBasicTest, Test2)
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