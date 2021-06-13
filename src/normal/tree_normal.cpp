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

/* 102. Binary Tree Level Order Traversal */

// Given the root of a binary tree, 
// return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

std::vector<std::vector<int>> Solution::levelOrder(TreeNode* root)
{
    std::vector<std::vector<int> > ret;
    if(!root)
    {
        return ret;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        std::size_t currentLevelSize = q.size();
        ret.push_back(std::vector<int>());
        for(std::size_t i = 0; i < currentLevelSize; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            ret.back().push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return ret;
}

/*106. Construct Binary Tree from Inorder and Postorder Traversal*/
/*
** @brief Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree 
**   and postorder is the postorder traversal of the same tree, construct and return the binary tree.
*/

TreeNode* Solution::buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
{
    post_index = static_cast<int>(postorder.size()) - 1;
    int idx = 0;
    for(auto& val: inorder){idx_map[val] = idx++;}
    return helper(0, post_index, inorder, postorder);
}

TreeNode* Solution::helper(int start, int end, std::vector<int>& inorder, std::vector<int>& postorder)
{
    if(start > end) {return nullptr;}
    int root_val = postorder[post_index];
    TreeNode* root = new TreeNode(root_val);
    int index = idx_map[root_val];
    post_index--;
    root->right = helper(index + 1, end, inorder, postorder);
    root->left = helper(start, index - 1, inorder, postorder); // ? why the right part should be built firstly.
    return root;
}


TreeNode*  Solution::buildTreePreorderAndInorder(std::vector<int>& inorder, std::vector<int>& preorder)
{
    int idx = 0;
    int n   = preorder.size();
    for(auto& val: inorder){idx_map[val] = idx++;}
    return helperv2(preorder, inorder, 0, n-1, 0, n-1);
}
TreeNode*  Solution::helperv2(const std::vector<int>& preorder, const std::vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
{
    if(preorder_left > preorder_right) return nullptr;
    int preorder_root       = preorder_left;
    int inorder_root        = idx_map[preorder[preorder_root]];
    // create the root node.
    TreeNode* root          = new TreeNode(preorder[preorder_root]);
    int size_left_subtree   = inorder_root  - inorder_left; // 前序遍历位置确定需要额外的信息 inorder_left. inorder_right可能不需要。
    root->left              = helperv2(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree,  inorder_left, inorder_root -1);
    root->right             = helperv2(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
    return root;
}