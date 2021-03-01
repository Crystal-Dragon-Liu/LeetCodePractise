#include "common/utils.h"
#include "gtest/gtest.h"
class MyCircularQueue;

/**
 * Test List:
MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false，队列已满
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4
*/

TEST(MyCircularQueueBasicTest, Test1)
{
    {
         MyCircularQueue myQueue = MyCircularQueue(3);
         EXPECT_EQ(true, myQueue.enQueue(1));

         EXPECT_EQ(true, myQueue.enQueue(2));
         EXPECT_EQ(true, myQueue.enQueue(3));
         EXPECT_EQ(false, myQueue.enQueue(4));
         myQueue.printQueue();
         EXPECT_EQ(3, myQueue.Rear());
         EXPECT_EQ(true, myQueue.isFull());
         EXPECT_EQ(true, myQueue.deQueue());
         myQueue.printQueue();
         EXPECT_EQ(true, myQueue.enQueue(4));
         EXPECT_EQ(4, myQueue.Rear());
         myQueue.printQueue();
    }

    {
        MyCircularQueue myQueue = MyCircularQueue(2);
        EXPECT_EQ(true, myQueue.enQueue(1));
        EXPECT_EQ(true, myQueue.enQueue(2));
        myQueue.printQueue();
        EXPECT_EQ(true, myQueue.deQueue());
        EXPECT_EQ(true, myQueue.enQueue(3));
        myQueue.printQueue();

        EXPECT_EQ(true, myQueue.deQueue());
        EXPECT_EQ(true, myQueue.enQueue(3));
        myQueue.printQueue();

        EXPECT_EQ(true, myQueue.deQueue());
        EXPECT_EQ(true, myQueue.enQueue(3));
        myQueue.printQueue();

        EXPECT_EQ(true, myQueue.deQueue());
        EXPECT_EQ(3, myQueue.Front());
        myQueue.printQueue();
    }


}