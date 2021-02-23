#include "gtest/gtest.h"
#include "normal/linked_list_normal.h"

class MyLinkedList;

/**
 * Test List:
 * 1. ensure the class MyLinkedList works well.
 * 2. test the interface "addAtHead"
 * 3. test the interface "addAtTail"
 * 4. test the interface "addAtIndex"
 * 5. test the interface "get"
 * 6. test the interface "deleteAtIndex"
*/
TEST(linkedListBasicTest, Test1)
{
    MyLinkedList* linkedList  = new MyLinkedList();
    // insert data.
    linkedList->addAtHead(1);
    linkedList->addAtHead(2);
    linkedList->printNodes();
}