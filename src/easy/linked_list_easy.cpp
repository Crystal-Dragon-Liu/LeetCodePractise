#include "common/utils.h"
#include "common/solution.h"

/* 141. linked list cycle*/


//------------------------------------------------------------------------

// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
//Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

// e.g.
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

//------------------------------------------------------------------------

bool Solution::hasCycle(ListNode* head)
{
        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;
        //traverse the link and make sure that the fast_ptr would be twice as fast as the slow_ptr,
        // and when the slow_ptr complete a cycle move, it would be catched by the fast_ptr precisely.
        while(fast_ptr != nullptr && fast_ptr->next != nullptr)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if(slow_ptr == fast_ptr) return true;
        }
        return false;
}

//TODO there may be some bugs to fix.
ListNode* Solution::getIntersectionNode(ListNode* headA, ListNode* headB)
{
    std::unordered_set<ListNode**> set;
    ListNode* tmp_node = headA;
    while(tmp_node)
    {
        set.insert(&tmp_node);
        tmp_node = tmp_node->next;
    }
    tmp_node = headB;
    while(tmp_node)
    {
        if(set.count(&tmp_node))
            return tmp_node;
    }
    return nullptr;
}

ListNode* Solution::reverseList(ListNode* head)
{
    // create a dummy_head for ListNode.
    ListNode* front_node = nullptr;
    ListNode* back_node = head;
    while(back_node != nullptr)
    {
        // reverse the front_node and back_node.
        ListNode* next_node = back_node->next;
        back_node->next = front_node;

        // switch to next group.
        front_node = back_node;
        back_node = next_node;
    }
    //delete dummy_head.
    return front_node;
}


ListNode* Solution::removeElements(ListNode* head, int val)
{
    ListNode* dummy_head = new ListNode(0, head);
    ListNode* prev_node = dummy_head;
    ListNode* cur_node = head;
    while(cur_node != nullptr)
    {
        if(cur_node->val == val)
        {
            prev_node->next = cur_node->next;
        }
        else
        {
            prev_node = cur_node;
        }
        cur_node = cur_node->next;
    }
    ListNode* ret = dummy_head->next;
    delete dummy_head;
    dummy_head = nullptr;
    return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

/*234. Palindrome Linked List*/

//------------------------------------------------------------------------------------------

// Given the head of a singly linked list, return true if it is a palindrome.

//------------------------------------------------------------------------------------------

bool Solution::isPalindrome(ListNode* head)
{
    std::vector<int> vals;
    // assignment for vals from ListNode.
    ListNode* tmp_node = head;
    while(tmp_node)
    {
        vals.emplace_back(tmp_node->val);
        tmp_node = tmp_node->next;
    }
    // check the vals.
    for(size_t i = 0, j = vals.size() - 1; i < j; i++, j--)
    {
        if(vals[j] != vals[i])
        {
            return false;
        }
    }
    return true;
}