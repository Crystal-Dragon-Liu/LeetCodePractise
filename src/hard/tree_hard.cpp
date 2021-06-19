#include "common/solution.h"
#include "common/utils.h"

//===================297. Serialize and Deserialize Binary Tree============================

// Serialization is the process of converting a data structure or object into a sequence of bits 
// so that it can be stored in a file or memory buffer, 
// or transmitted across a network connection link to be reconstructed later 
// in the same or another computer environment.
// Design an algorithm to serialize and deserialize a binary tree. 
// There is no restriction on how your serialization/deserialization algorithm should work.
//  You just need to ensure that a binary tree can be serialized to a string 
//  and this string can be deserialized to the original tree structure.
// Clarification: The input/output format is the same as how LeetCode serializes a binary tree.
// You do not necessarily need to follow this format,
//  so please be creative and come up with different approaches yourself.
//=========================================================================================

const char L_BRACKET = '(';
const char R_BRACKET = ')';
const std::string NONE_NODE_STR = "X";
const char NONE_NODE_CHR = 'X';




std::string                     Solution::serialize(TreeNode* root)
{
    if(!root) return std::string(NONE_NODE_STR);
    std::string l_data = L_BRACKET + serialize(root->left) + R_BRACKET;
    std::string r_data = L_BRACKET + serialize(root->right) + R_BRACKET;
    return l_data + std::to_string(root->val) + r_data;
}
TreeNode*                       Solution::deserialize(std::string data)
{
    int ptr = 0; /// define a index that current location that we need to parse.
    return parse(data, ptr);
}

TreeNode*                       Solution::parse(const std::string& data, int& ptr)
{
    if(data[ptr] == NONE_NODE_CHR){++ptr;return nullptr;} /// there is no node
    auto cur    = new TreeNode(0);
    cur->left   = parseSubtree(data, ptr);
    cur->val    = parseInt(data, ptr);
    cur->right  = parseSubtree(data, ptr);
    return cur;   
}
int                             Solution::parseInt(const std::string& data, int& ptr)
{
    int x = 0, sgn = 1;
    if(!isdigit(data[ptr])){sgn = -1; ++ptr;}
    while(isdigit(data[ptr])){x  = x * 10 + data[ptr++] - '0';}
    return x * sgn;
}
TreeNode*                       Solution::parseSubtree(const std::string& data, int& ptr)
{
    ++ptr; // skip L_BRACKET
    auto subtree = parse(data, ptr);
    ++ptr; // skip R_BRACKET
    return subtree;
}
