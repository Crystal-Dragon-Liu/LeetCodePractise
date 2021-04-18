#include "common/solution.h"
#include "common/utils.h"


/*104. Maximum Depth of Binary Tree*/
/* 
** @brief Given the root of a binary tree, return its maximum depth.
** A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
int Solution::maxDepth(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    int left_max = maxDepth(root->left);
    int right_max = maxDepth(root->right);
    return std::max(left_max, right_max) + 1;
}


/*101. Symmetric Tree*/
/*
** @brief  Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/

bool Solution::isSymmetric(TreeNode* root)
{
    return check(root, root);
}

bool Solution::check(TreeNode* p, TreeNode* q)
{
    if(!p && !q) return true;
    if(!p || !q) return false; // one node is set to null,but not for the other side.
    return (p->val == q->val) && check(q->right, p->left) && check(p->right, q->left);
}

/*
** @brief Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
** A leaf is a node with no children. 
*/

bool Solution::hasPathSum(TreeNode* root, int targetSum)
{
    if(root == nullptr) return false;
    if(root->left == nullptr && root->right == nullptr)
        return root->val == targetSum;
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}