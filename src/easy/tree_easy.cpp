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
//========================= 剑指 Offer 68 - II. 二叉树的最近公共祖先======================
// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
// 最近公共祖先表示为一个结点 x，
// 满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
// 示例 1:
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// 输出: 3
// 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
// 示例 2:
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// 输出: 5
// 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
//=========================================================================================

bool  Solution::dfsForLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!root) return false;
    bool lson = dfsForLowestCommonAncestor(root->left, p, q);
    bool rson = dfsForLowestCommonAncestor(root->right, p, q);
    if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;}
    return lson || rson || (root->val == p->val) || (root->val == q->val); 
}

TreeNode*  Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    /// condition ->  flson && frson || ((x == q || x == p) && (flson || frson) )
    dfsForLowestCommonAncestor(root, p, q);
    return ans;

}

//===================                100. Same Tree            ============================
// Given the roots of two binary trees p and q, 
// write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical,
// and the nodes have the same value.
//=========================================================================================

bool       Solution::isSameTree(TreeNode* p, TreeNode* q)
{
    if(!p && !q) return true;
    else if (!p || !q) return false;
    else if (p->val != q->val) return false;
    else
    {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}
