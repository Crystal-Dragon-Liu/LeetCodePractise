#ifndef UTILS_H
#define UTILS_H
#include "common/config.h"

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode* next): val(x), next(next){}
      ListNode(): val(0), next(nullptr) {}
  };


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
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

class MyLinkedList {
public:
    /*struct for linked node*/
    struct LinkedNode
    {
        LinkedNode(int val): _val(val), _next(nullptr){}
        /* data */
        LinkedNode* _next = nullptr;
        int _val = -1;
        LinkedNode(int x, LinkedNode* next): _val(x), _next(next){}
        LinkedNode(): _val(-1), _next(nullptr) {}
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        //create a header without data.
        _dummy_head = new LinkedNode(-1);
        //initialize the size.
        _size = 0;
    }


    ~MyLinkedList()
    {
        int index = _size;
        while(index)
        {
            LinkedNode* node = at(index);
            delete node;
            index--;
        }
        if(_dummy_head != nullptr) delete _dummy_head;
    }
    void insertNode(LinkedNode* node, LinkedNode* position_node)
    {
        if(node == nullptr && position_node == nullptr) return;
        node->_next = position_node->_next;
        position_node->_next = node;
        _size++;
    }
    void printNodes()
    {
        LinkedNode* node = _dummy_head;
        std::cout << "==================" << "print nodes" << "==================" << std::endl;
        while(node != nullptr)
        {
            std::cout << "==================" << node->_val << "==================" << std::endl;
            node = node->_next;
        }
    }
    LinkedNode* at(int index)
    {
        //notice the boundary condition.
        if(index > _size || index < 0) return nullptr;
        LinkedNode* cur_node = _dummy_head;
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


//------------------------------------------------------------------------------------------------------------//

// Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".
// One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.
// Implementation the MyCircularQueue class:

class MyCircularQueue {
public:
MyCircularQueue(int k):_size(k) {
        _data = new int[_size];
    }
    int Index(int** target_node)
    {
        if(*target_node == nullptr) return INVALID_VALUE;
        size_t i = 0;
        while(i < _size)
        {
            if((_data + i) == *target_node) return i;
            i++;
        }
        return -1;
    }
    void updateTailIndex()
    {
            int index = Index(&_tail_position);
            index = (index + 1) % _size;
            _tail_position = _data + index;
    }
    void updateHeadIndex()
    {
            int index = Index(&_head_position);
            index = (index + 1) % _size;
            _head_position = _data + index;
    }
    ~MyCircularQueue()
    {
        if(_size != 0) delete[] _data;
    }
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            //assign the value for the first element.
            *_data = value;
            _head_position = _data;
            _tail_position = _data;
            return true;
        }
        else{
            //TODO maybe there are some bugs.
            updateTailIndex();
            *_tail_position = value;
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(_head_position == _tail_position) //there is only one element in the queue.
        {
            _head_position = nullptr;
            _tail_position = nullptr;
            return true;
        }
        else
        {
            // _head_position = (_head_position + 1) % _size;
            updateHeadIndex();
            return true;
        }
    }
    
    int Front() {
        if(isEmpty()) return INVALID_VALUE;
        return *_head_position;
    }
    
    int Rear() {
        if(isEmpty()) return INVALID_VALUE;
        return *_tail_position;
    }
    
    bool isEmpty() {
        if(_head_position == nullptr) return true;
        else return false;
    }
    
    bool isFull() {
        int index_tail = Index(&_tail_position);
        int index_head = Index(&_head_position);
        if(index_tail == -1 || index_head == -1)
            return false;
        return (index_tail + 1) % int(_size) == index_head ? true: false;
    }
    void printQueue()
    {
        std::cout << "================print all the data================" << std::endl;
        for(size_t i = 0; i < _size; i++)
        {
            std::cout << "===========" << _data[i] << "===========" << std::endl;
        }
    }
private:
    int* _data = nullptr;
    size_t _size = 0;
    int* _head_position = nullptr;
    int* _tail_position = nullptr;
};
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


//------------------------------------------------------------------------------------------------------------//
// Design a HashSet without using any built-in hash table libraries.

// Implement MyHashSet class:

// void add(key) Inserts the value key into the HashSet.
// bool contains(key) Returns whether the value key exists in the HashSet or not.
// void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.


#include <vector>
struct Node{
    int _val;
    Node* _next;
    Node(int val):_val(val), _next(nullptr){}
};
const int len  = 100;
using Bucket =  std::vector<Node*>;
using num_list = std::vector<int>;
class MyHashSet
{
public:

    MyHashSet(){
        // _bucket = Bucket(len, new Node(INVALID_VALUE));
        for(int i = 0; i < len; i++)
        {
            _bucket.push_back(new Node(INVALID_VALUE));
            _num_list.push_back(0);
        }
        // operator new is to create a list of node with the dummy head which contains no data.
    }
    // TODO there are still many bugs regarding to destruction.
    ~MyHashSet()
    {
        for(size_t i = 0; i < _bucket.size(); i++)
        {
            if(_bucket[i]->_next == nullptr)
            {
                delete _bucket[i];
                _bucket[i] = NULL;
            }
            else
            {
                int index = _num_list[i];
                //delete the rest of nodes.
                 while(index)
                {
                        Node* node = at(i, index);
                        delete node;
                        index--;
                }
                if(_bucket[i] != nullptr)
                {
                    delete _bucket[i];
                    _bucket[i] = NULL;
                }
            }
        }
        _bucket.clear();
        _bucket.shrink_to_fit();
    }
    Node* at(int index_bucket, int index)
    {
        //notice the boundary condition.
        if(index > _num_list[index_bucket] || index < 0) return nullptr;
        Node* cur_node = _bucket[index_bucket];
        while(index-- && cur_node != nullptr)
        {
            cur_node = cur_node->_next;
        }
        return cur_node;
    }

    void add(int key)
    {
        int hash_value = key % len;
        //TODO we should find the first node, which are the next to the dummyhead node,storing the key
        Node* dummy_head = _bucket[hash_value];// this is dummy head that has no data(key).
        Node* temp_node = dummy_head->_next;
        // if there is no key to store
        if(temp_node == nullptr) 
        {
            // the first node didn't store any key, meaning we could directly store our "key".
            Node* node = new Node(key);
            dummy_head->_next = node;
            _num_list[hash_value]++;
            return;
        }
        //  if(temp_node->_val == -1) {
        //      temp_node->_val = key;
        //      return;
        // }
        else{
            while(temp_node)
            {
                if(temp_node->_val == key) return; //this key has been added to MyHashSet obj.
                if(temp_node->_val == -1)
                {
                    temp_node->_val = key;
                    _num_list[hash_value]++;
                    return;
                }
                if(!(temp_node->_next))
                {
                    //if there is no more Node ptr to store the key.
                    Node* node = new Node(key);
                    temp_node->_next = node;
                    _num_list[hash_value]++;
                    return;
                }
                temp_node = temp_node->_next;
            }
        }
    }
    void remove(int key)
    {
        int hash_value = key % len;
        Node* dummy_head = _bucket[hash_value];
        Node* temp_node = dummy_head->_next;
        //searching the key we stored before.
        if(temp_node != nullptr)
        {
            while(temp_node)
            {
                if(temp_node->_val == key)
                    {
                        temp_node->_val = -1;
                        // _num_list[hash_value]--;
                        return;
                    }
                temp_node = temp_node->_next;
            }
        }
    }
    bool contains(int key)
    {
        int hash_value = key % len;
        Node* dummy_head = _bucket[hash_value];
        Node* temp_node = dummy_head->_next;
        while(temp_node){
            if(temp_node->_val == key) return true;
            temp_node = temp_node->_next;
        }
        return false;
    }

    // void deleteAtIndex(int hash_value, int key) {
    //     // if(index > _size || index < 0) return;
    //     // LinkedNode* cur_node = at(index);
    //     Node* cur_node = _bucket[hash_value];
    //     if(cur_node->_next == nullptr) return;
    //     else{
    //         while ()
    //         {
    //             /* code */
    //         }
            
    //     }
    //     Node* deleted_node = cur_node->_next;
    //     if(deleted_node == nullptr) return;
    //     cur_node->_next = cur_node->_next->_next;
    //     delete deleted_node;
    // }

    void print_all_buckets()
    {
        for(size_t i = 0; i < _bucket.size(); i++)
        {
            //print each buckets
            Node* node = _bucket[i];
            std::cout << STRIP_BAR << "buckets:" << i << STRIP_BAR << std::endl;
            while(node != nullptr)
            {
                std::cout << STRIP_BAR << node->_val << STRIP_BAR << std::endl;
                node = node->_next;
            }
        }
    }
private:
    Bucket _bucket;
    num_list _num_list; // this vector is about to store the size of each bucket.
};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


//------------------------------------------------------------------------------------------------------------//
// Design a HashMap without using any built-in hash table libraries.

// To be specific, your design should include these functions:

// put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
// get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.


struct HashNode
{
    int _key;
    int _value;
    HashNode* _next;
    HashNode(int key, int value): _key(key), _value(value), _next(nullptr){}
};
using HashBucket = std::vector<HashNode*>;
#define INVALID_KEY -1
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        for(int i = 0; i < len; i++)
        {
            _bucket.push_back(new HashNode(INVALID_KEY, INVALID_VALUE));
            _num_list.push_back(0);
        }
    }
    ~MyHashMap()
    {
        for(size_t i = 0; i < _bucket.size(); i++)
        {
            if(_bucket[i]->_next == nullptr)
            {
                delete _bucket[i];
                _bucket[i] = NULL;
            }
            else
            {
                int index = _num_list[i];
                //delete the rest of nodes.
                 while(index)
                {
                        HashNode* node = at(i, index);
                        delete node;
                        index--;
                }
                if(_bucket[i] != nullptr)
                {
                    delete _bucket[i];
                    _bucket[i] = NULL;
                }
            }
        }
        _bucket.clear();
        _bucket.shrink_to_fit();
    }
    
    HashNode* at(int index_bucket, int index)
    {
        //notice the boundary condition.
        if(index > _num_list[index_bucket] || index < 0) return nullptr;
        HashNode* cur_node = _bucket[index_bucket];
        while(index-- && cur_node != nullptr)
        {
            cur_node = cur_node->_next;
        }
        return cur_node;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash_index = key % len;
        // search the bucket.
        if(_bucket[hash_index]->_next == nullptr)
        {
            //there is no key stored by users before, so we need to create it firstly.
            HashNode* node = new HashNode(key, value);
            _bucket[hash_index]->_next = node;
            _num_list[hash_index]++;
            return;
        }
        HashNode* cur_node = _bucket[hash_index];
        while(cur_node->_next)
        {
            if(cur_node->_next->_key == key)
                {
                    cur_node->_next->_value = value;
                    return;
                }
            cur_node = cur_node->_next;
        }
        //we have reach the tail of list.
        HashNode* node = new HashNode(key, value);
        cur_node->_next = node;
        _num_list[hash_index]++;       
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash_index = key % len;
        if(_bucket[hash_index]->_next == nullptr)
        {
            return INVALID_VALUE;
        }
        HashNode* cur_node = _bucket[hash_index];
        while(cur_node->_next)
        {
            if(cur_node->_next->_key == key)
            {
                return cur_node->_next->_value;
            }
            cur_node = cur_node->_next;
        }
        // there is no value we could find by searching the key provided by users.
        return INVALID_VALUE;
    }

    void print_all_buckets()
    {
        for(size_t i = 0; i < _bucket.size(); i++)
        {
            //print each buckets
            HashNode* node = _bucket[i];
            
            if(node->_next!= nullptr)
            {
                std::cout << STRIP_BAR << "buckets:" << i << STRIP_BAR << std::endl;
                while(node != nullptr)
                {
                    std::cout << STRIP_BAR << node->_key << "," << node->_value << STRIP_BAR << std::endl;
                    node = node->_next;
                }
            } 
        }
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hash_value = key % len;
        if(_bucket[hash_value]->_next == nullptr)
        {
            // the bucket[hash_value] is set to empty which means there is no key input.
            return;
        }
        HashNode* cur_node = _bucket[hash_value];
        HashNode* next_node = cur_node->_next;
        while(next_node)
        {
            if(next_node->_key == key)
            {
                if(next_node->_next)
                {
                    cur_node->_next = next_node->_next;
                }
                else{
                    cur_node->_next = nullptr;
                }
                delete next_node;
                _num_list[hash_value]--;
                return;
            }
            cur_node = next_node;
            next_node = next_node->_next;
        }
    }
private:
    HashBucket _bucket;
    num_list _num_list;
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */


template<typename _Tp> _Tp stringToTp(std::string &str)
{
    std::istringstream iss(str);
    _Tp num;
    iss >> num;
    return num;
}
/*
 * @brief read data from .csv files.
 */
template<typename _Tp> std::vector<std::vector<_Tp> > read_data_from_csv_2d(std::string path)
{
    std::ifstream inFile(path, std::ios::in);
    std::vector<std::vector<_Tp> > result;
    std::vector<_Tp> result_temp;
    std::string lineStr;
    while(getline(inFile, lineStr))
    {
        std::stringstream ss(lineStr);
        std::string str;
        while(getline(ss, str, ','))
        {
            result_temp.push_back(stringToTp<_Tp>(str));
        }
        result.push_back(result_temp);
        result_temp.clear();
    }
//    Size(result, "result");
    return result;
}

template<typename _Tp> std::vector<_Tp> read_data_from_csv_1d(std::string path)
{
    std::ifstream in_file(path, std::ios::in);
    std::vector<_Tp> result;
    std::string line_str;
    getline(in_file, line_str);
    std::stringstream ss(line_str);
    std::string str;
    while(getline(ss, str, ','))
    {
        result.push_back(stringToTp<_Tp>(str));
    }
    return result;
}


extern std::vector<int> splitInt(int n);
extern void printLinkedNodes(ListNode* start_node);


#endif