#include "common/utils.h"
#include "common/solution.h"
#include <stack>
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/*142.Linked List Cycle 2 */

//------------------------------------------------------------------------------------------

// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Notice that you should not modify the linked list.


// Input: head = [3,2,0,-4], pos = 1
//Output: tail connects to node index 1
//Explanation: There is a cycle in the linked list, where tail connects to the second node.

//------------------------------------------------------------------------------------------

ListNode * Solution::detectCycle(ListNode *head)
{
    ListNode* fast_node = head;
    ListNode* slow_node = head;
    while(true)
    { if(fast_node == nullptr && fast_node->next == nullptr) return nullptr;
        slow_node = slow_node->next;
        if(fast_node->next->next == nullptr) return nullptr;
        else
        {
             fast_node = fast_node->next->next;
            if(fast_node == slow_node) break;
        }
       
    }
    fast_node = head;
    while(fast_node != slow_node)
    {
        fast_node = fast_node->next;
        slow_node = slow_node->next;
    }
    return fast_node;
}

// 19
// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Follow up: Could you do this in one pass?

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    // return nullptr;
    ListNode* dummy_head = new ListNode(0, head); // define a dummy_head for ListNode.
    std::stack<ListNode*> stk;
    ListNode* cur_node = dummy_head;
    while(cur_node)
    {
        stk.push(cur_node);
        cur_node = cur_node->next;
    }
    for(int i = 0; i < n; i++)
    {
        stk.pop();
    }
    ListNode* prev = stk.top();
    if(prev)
    {
        //delete the node
        ListNode* deleted_node = prev->next;
        if(deleted_node)
        {
            prev->next = deleted_node->next;
            delete prev->next;
            prev->next = nullptr;
        }
    }
    ListNode* ans = dummy_head->next;
    delete dummy_head;
    dummy_head = nullptr;
    return ans;
}