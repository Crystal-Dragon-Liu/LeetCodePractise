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

/* 94. Binary Tree Inorder Traversal */
// Given the root of a binary tree, return the inorder traversal of its nodes' values.

std::vector<int> Solution::inorderTraversal(TreeNode* root)
{
    std::vector<int> result;
    if(root)
    {
        // traverse the left nodes.
        inTraversal(root->left, result);
        // insert the root.
        result.emplace_back(root->val);
        // traverse the right nodes.
        inTraversal(root->right, result);
        return result;
    }
    else{
        return result;
    }
}
void Solution::inTraversal(TreeNode* root, std::vector<int>& data)
{
    if(root)
    {

        // traverse the left nodes.
        inTraversal(root->left, data);
        // push back the root node.
        data.emplace_back(root->val);
        // traverse the right nodes.
        inTraversal(root->right, data);
    }
}
/* 145. Binary Tree Postorder Traversal */
// Given the root of a binary tree, return the postorder traversal of its nodes' values.

std::vector<int> Solution::postorderTraversal(TreeNode* root)
{
    std::vector<int> result;
    if(root)
    {
        // traverse the left nodes.
        postTraversal(root->left, result);
        // traverse the right nodes.
        postTraversal(root->right, result);
        // insert the root.
        result.emplace_back(root->val);
        return result;
    }
    else{
        return result;
    }
}
void Solution::postTraversal(TreeNode* root, std::vector<int>& data)
{
    if(root)
    {

        // traverse the left nodes.
        postTraversal(root->left, data);
        // traverse the right nodes.
        postTraversal(root->right, data);
        // push back the root node.
        data.emplace_back(root->val);
    }
}