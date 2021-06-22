#include "common/solution.h"
#include "common/utils.h"
#include <math.h>
#include <algorithm>

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

//===================      111. Minimum Depth of Binary Tre    ============================
// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path 
// from the root node down to the nearest leaf node.
// Note: A leaf is a node with no children.
//=========================================================================================
int                             Solution::minDepth(TreeNode* root)
{
    if(!root) return 0;
    std::queue<std::pair<TreeNode*, int> > que;
    que.emplace(root, 1);
    while (!que.empty())
    {
        // traverse
        TreeNode* node = que.front().first;
        int depth = que.front().second;
        que.pop();
        if(!node->left && !node->right){ return depth;}
        if(node->left) que.emplace(node->left, depth+1);
        if(node->right) que.emplace(node->right, depth+1);
    }
    return 0;
}

//===================      111. Minimum Depth of Binary Tre    ============================
// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as:
// a binary tree in which the left 
// and right subtrees of every node differ in height by no more than 1.
//=========================================================================================
bool                            Solution::isBalanced(TreeNode* root)
{
    if(root == NULL) return true;
    else{
        return abs(height(root->right) - height(root->left)) <= 1 && isBalanced(root->left) == isBalanced(root->right);
    }
}

int                             Solution::height(TreeNode* root)
{
    if(!root) return 0;
    else return std::max(height(root->left), height(root->right)) + 1;

}

//=========================================================================================
// *********108. Convert Sorted Array to Binary Search Tree**************
// Given an integer array nums where the elements are sorted in ascending order,
//  convert it to a height-balanced binary search tree.
// A height-balanced binary tree is a binary tree
//  in which the depth of the two subtrees of every node never differs by more than one.
//=========================================================================================
TreeNode*                       Solution::sortedArrayToBST(std::vector<int>& nums)
{
    return sortedArrayToBSTHelper(nums, 0, nums.size()-1);
}

TreeNode*                       Solution::sortedArrayToBSTHelper(std::vector<int> & nums, int left, int right)
{
    if(left > right) return nullptr;
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBSTHelper(nums, left, mid -1);
    root->right = sortedArrayToBSTHelper(nums, mid+1, right);
    return root;
}
//=========================================================================================
// 257. Binary Tree Paths
// Given the root of a binary tree,
// return all root-to-leaf paths in any order.
// A leaf is a node with no children.
//=========================================================================================
std::vector<std::string>        Solution::binaryTreePaths(TreeNode* root)
{
    std::vector<std::string> paths;
    buildPath(root, "", paths);
    return paths;
} 

void   Solution::buildPath(TreeNode* root, std::string path, std::vector<std::string>& pathList)
{
    if(root)
    {
        path += std::to_string(root->val);
        if(!root->left && !root->right) pathList.push_back(path);
        else
        {
            path += "->";
            buildPath(root->left, path, pathList);
            buildPath(root->right, path, pathList);
        }
    } 
}