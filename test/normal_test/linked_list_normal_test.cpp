#include "gtest/gtest.h"
#include "common/utils.h"
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