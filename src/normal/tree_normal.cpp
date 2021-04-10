#include "common/solution.h"
#include "common/utils.h"


/* 144. Binary Tree Preorder Traversal */
// Given the root of a binary tree, return the preorder traversal of its nodes' values.

std::vector<int> Solution::preorderTraversal(TreeNode* root)
{
    std::vector<int> result;
    if(root)
    {
        result.emplace_back(root->val);
        // traverse the left nodes.
        preTraversal(root->left, result);
        // traverse the right nodes.
        preTraversal(root->right, result);
        return result;
    }
    else
    {
        return result;
    }


}

void Solution::preTraversal(TreeNode* root, std::vector<int>& data)
{
    if(root)
    {
        // push back the root node.
        data.emplace_back(root->val);
        // traverse the left nodes.
        preTraversal(root->left, data);
        // traverse the right nodes.
        preTraversal(root->right, data);
    }
}
