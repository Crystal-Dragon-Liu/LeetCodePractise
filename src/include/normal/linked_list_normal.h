
//---------------------------------------------------------------------------
//Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
//A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
//If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

// Implement the MyLinkedList class:

// MyLinkedList() Initializes the MyLinkedList object.
// int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
// void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
// void addAtTail(int val) Append a node of value val as the last element of the linked list.
// void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
// void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
//---------------------------------------------------------------------------

//virtual header.
#include <iostream>

#define INVALID_VALUE -1;

class MyLinkedList {
public:
    /*struct for linked node*/
    struct LinkedNode
    {
        LinkedNode(int val): _val(val), _next(nullptr){}
        /* data */
        LinkedNode* _next = nullptr;
        int _val = -1;
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        //create a header without data.
        _dummy_head = new LinkedNode(-1);
        //initialize the size.
        _size = 0;
    }

    void insertNode(LinkedNode* node, LinkedNode* position_node)
    {
        if(node == nullptr || position_node == nullptr) return;
        node->_next = position_node->_next;
        position_node->_next = node;
        _size++;
    }
    void printNodes()
    {
        LinkedNode* node = _dummy_head;
        std::cout << "==================" << "print nodes" << "==================" << std::endl;
        while(node->_next != nullptr)
        {
            std::cout << "==================" << node->_val << "==================" << std::endl;
            node = node->_next;
        }
    }
    LinkedNode* at(int index)
    {
        //notice the boundary condition.
        if(index > _size - 1 || index < 0) return nullptr;
        LinkedNode* cur_node = _dummy_head->_next;
        while(index--)
        {
            cur_node = cur_node->_next;
        }
        return cur_node;
    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        //notice the boundary condition.
        if(index >= _size || index < 0) return INVALID_VALUE;
        LinkedNode* cur_node = _dummy_head->_next;
        while(index--)
        {
            cur_node = cur_node->_next;
        }
        return cur_node->_val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {

                LinkedNode* new_node = new LinkedNode(val);
                LinkedNode* cur_node = _dummy_head;
                insertNode(new_node, cur_node);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode* new_node = new LinkedNode(val);
        LinkedNode* cur_node = at(_size);
        insertNode(new_node, cur_node);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > _size || index < 0) return;
        if(index == _size){
            addAtTail(val);
            return;
        }
        if(index < 0){
            addAtHead(val);
            return;
        }
        LinkedNode* new_node = new LinkedNode(val);
        LinkedNode* cur_node = at(index);
        insertNode(new_node, cur_node);
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index > _size || index < 0) return;
        LinkedNode* cur_node = at(index);
        if(cur_node == nullptr) return;
        LinkedNode* deleted_node = cur_node->_next;
        if(deleted_node == nullptr) return;
        cur_node->_next = cur_node->_next->_next;
        delete deleted_node;
        _size--;
    }
private:
    LinkedNode* _dummy_head;
    int _size;

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */