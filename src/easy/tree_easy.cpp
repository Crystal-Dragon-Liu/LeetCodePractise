#include "common/solution.h"
#include "common/utils.h"
#include <math.h>
#include <algorithm>
#include <stack>

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

int  Solution::maxDepthPostOrder(TreeNode* root)
{
    if(!root) return 0;
    std::stack<TreeNode*> st;
    st.push(root);
    int depth = 0;
    int result = 0;
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        if(node){
            st.push(node);
            st.push(NULL);
            depth++;
            if(node->left)
                st.push(node->right);
            if(node->right)
                st.push(node->left);
        }
        else{
            st.pop();
            node = st.top();
            st.pop();
            depth--;
        }
        result = result > depth ? result: depth;
    }
    return depth;
}


int  Solution::maxDepthLevelOrder(TreeNode* root){
    if(root == nullptr)
        return 0;
    std::queue<TreeNode*> q;
    q.push(root);
    int result = 1;
    while(!q.empty()){
        std::size_t size = q.size();
        for(std::size_t i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result++;
    }
    return result;
}

int Solution::maxDepth(NTree::Node* root)
{
    if(root == nullptr)
        return 0;
    std::queue<NTree::Node*> q;
    int result = 1;
    q.push(root);
    while(!q.empty()){
        std::size_t size = q.size();
        for(std::size_t i = 0; i < size; i++){
            NTree::Node* node = q.front();
            q.pop();
            for(std::size_t j = 0; j < node->children.size(); i++)
                if(node->children[i]) q.push(node->children[i]);
        }
        result++;
    }
    return result;
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

bool  Solution::checkV2(TreeNode* p, TreeNode* q)
{
    if(!p && !q)
        return true;
    else if(!p&&q)
        return false;
    else if(!q&&p)
        return false;
    else if(q->val != p->val)
        return false;
    bool left = checkV2(q->left, p->right);
    bool right = checkV2(p->left, q->right);
    return left && right;
}

bool Solution::isSymmetricV2(TreeNode* root)
{
    if(!root) return true;
    std::queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);
    while(!q.empty()){
        TreeNode* node_left = q.front();
        q.pop();
        TreeNode* node_right = q.front();
        q.pop();
        if(!node_left&&!node_right)
        {
            continue;
        }
        else if(!node_left&&node_right) return false;
        else if(node_left && !node_right) return false;
        else if(node_right->val != node_left->val) return false;
        q.push(node_right->left);
        q.push(node_left->right);
        q.push(node_right->right);
        q.push(node_left->left);
    }
    return true;
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

int    Solution::minDepthRecursive(TreeNode* root)
{
    // if(!root) return 0;
    // if(!root->left && !root->right) return 1;
    // int depth;
    // if(!root->left)
    //     depth = 1 + minDepthRecursive(root->right);
    // if(!root->right)
    //     depth = 1 + minDepthRecursive(root->left);
    // return depth;
    if(!root) return 0;
    int leftDepth = minDepthRecursive(root->left);
    int rightDepth = minDepthRecursive(root->right);
    if(!root->left && root->right)
        return 1 + rightDepth;
    if(!root->right && root->left)
        return 1 + leftDepth;
    return 1 + std::min(leftDepth, rightDepth);
}

int   Solution::minDepthIterator(TreeNode* root){
    if(!root) return 0;
    std::queue<TreeNode*> queue;
    queue.push(root);
    int minDepth = 0;
    while(!queue.empty()){
        std::size_t size = queue.size();
        minDepth++;
        for(std::size_t i = 0; i < size; i++){
            TreeNode* node = queue.front();
            queue.pop();
            if(node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);
            if(!node->left&&!node->right)
                return minDepth;
        }
    }
    return minDepth;
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
// ? 257. Binary Tree Paths
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

std::vector<std::string>     Solution::binaryTreePathsIter(TreeNode* root){

    std::vector<std::string> pathSet;
    std::stack<TreeNode*>    st;
    std::stack<std::string>  pathStack;
    if(!root) return pathSet;
    st.push(root);
    pathStack.push(std::to_string(root->val));
    while(!st.empty()){
        TreeNode* node = st.top();
        if(node){
            st.pop();
            // get the path where there is current node.
            auto path = pathStack.top(); pathStack.pop();
            if(!node->right && !node->left)
                {pathSet.push_back(path);}
            //front order.
            if(node->right){
                st.push(node->right);
                pathStack.push(path + "->" + std::to_string(node->right->val));
            }
            if(node->left){
                st.push(node->left);
                pathStack.push(path + "->" + std::to_string(node->left->val));
            }
            st.push(node);
            st.push(NULL);
        }
        else{
            st.pop();
            // TreeNode* node = st.top();
            st.pop();
        }
    }
    return pathSet;
}

//=========================================================================================
//? 637. Average of Levels in Binary Tree
// Given the root of a binary tree,
// return the average value of the nodes on each level in the form of an array. 
// Answers within 10-5 of the actual answer will be accepted.
//=========================================================================================

std::vector<double>     Solution::averageOfLevels(TreeNode* root)
{
    std::queue<TreeNode*> queue;
    std::vector<double> result;
    queue.push(root);
    while(!queue.empty()){
        std::size_t size = queue.size();
        int sum = 0;
        for(std::size_t i = 0; i < size; i++){
            TreeNode* node = queue.front();
            sum += node->val;
            queue.pop();
            if(node->left)
                queue.push(node->left);
            if(node->right)
                queue.push(node->right);
        }
        result.push_back(sum /size);
    }
    return result;
}

//=========================================================================================
//? 515. Find Largest Value in Each Tree Row
// Given the root of a binary tree,
// return the average value of the nodes on each level in the form of an array. 
// Answers within 10-5 of the actual answer will be accepted.
//=========================================================================================
std::vector<int>  Solution::largestValues(TreeNode* root)
{
    std::queue<TreeNode*> q;
    std::vector<int> result;
    auto max = INT32_MIN;
    if(root) q.push(root);
    while(!q.empty()){
        std::size_t size = q.size();
        for(std::size_t i = 0; i < size; i++){
            TreeNode* node = q.front();
            max = std::max(max, node->val);
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        result.push_back(max);
        max = INT32_MIN;
    }
    return result;
}


//=========================================================================================
//? 226. Invert Binary Tree
// Given the root of a binary tree, invert the tree, and return its root.
//=========================================================================================
TreeNode*     Solution::invertTree(TreeNode* root)
{
    if(!root) return root;
    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

TreeNode*    Solution::invertTreeIterFront(TreeNode* root)
{
    if(!root) return root;
    std::stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        // process data.
        std::swap(root->left, root->right);
        if(node->left)
            st.push(node->right);
        if(node->right)
            st.push(node->left);
    }
    return root;
}

TreeNode*   Solution::invertTreeIterCommonFront(TreeNode* root){
    if(!root) return root;
    std::stack<TreeNode*> st;
    std::vector<int> result;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        if(node){
            // process node.
            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
            st.push(node);
            st.push(nullptr);
        }
        else{
            // when we traverse the root node, processing the data.
            st.pop();
            TreeNode* node = st.top();
            st.pop();
            std::swap(node->left, node->right);
        }
    }
    return root;
}

TreeNode*  Solution::invertTreeLevelOrder(TreeNode* root)
{
    if(!root) return root;
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        std::size_t size = q.size();
        for(std::size_t i = 0; i < size; i++){
            // process data.
            TreeNode* node = q.front();
            q.pop();
            std::swap(node->left, node->right);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    return root;
}

//=========================================================================================
// ? 3. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without repeating characters.
//=========================================================================================

int  Solution::lengthOfLongestSubstring(std::string s){
    // // 记录字符上一次出现的位置
    //     int[] last = new int[128];
    //     for(int i = 0; i < 128; i++) {
    //         last[i] = -1;
    //     }
    //     int n = s.length();

    //     int res = 0;
    //     int start = 0; // 窗口开始位置
    //     for(int i = 0; i < n; i++) {
    //         int index = s.charAt(i);
    //         start = Math.max(start, last[index] + 1);
    //         res   = Math.max(res, i - start + 1);
    //         last[index] = i;
    //     }

    //     return res;
    std::vector<int> last(128, -1);
    int n = s.length();
    int res = 0;
    int start = 0;
    for(int i = 0; i < n; i++){
        int index = s.at(i);
        start = std::max(start, last[index] + 1);
        res   = std::max(res, i - start + 1);
        last[index] = i;
    }
    return res;
}

//=========================================================================================
// ?110. Balanced Binary Tree
// Given a binary tree, 
// determine if it is height-balanced.
// For this problem, 
// a height-balanced binary tree is defined as:
// a binary tree in which the left and right subtrees of every node differ 
// in height by no more than 1.
//=========================================================================================
int Solution::isBalancedBinaryTree(TreeNode* root){
    // if root equal to 0, height is set to 0;
    if(!root) return 0;
    int height_left = height(root->left);
    int height_right = height(root->right);
    if(height_left == -1)
        return -1;
    if(height_right == -1)
        return -1;
    return std::abs(height_left - height_right) >1 ? -1:  1 + std::max(height_right, height_left);
}

int Solution::isBalancedBinaryTreeIter(TreeNode* root){
    if(!root)
        return 0;
    std::stack<TreeNode*> st;
    st.push(root);
    int depth = 0;
    int result = 0;
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        if(node){
            st.push(node);
            st.push(NULL);
            depth++;
            if(node->left)
                st.push(node->right);
            if(node->right)
                st.push(node->left);
        }
        else{
            st.pop();
            st.pop();
            depth--;
        }
        result = result > depth ? result: depth;
        // update
    }
    return result;
}

//=========================================================================================
//? 404. Sum of Left Leaves
// Given the root of a binary tree, return the sum of all left leaves.
//=========================================================================================
int   Solution::sumOfLeftLeaves(TreeNode* root){ 
    if(!root) return 0;
    int leftSum = 0;
    int rightSum = 0;
    if(root->left && !root->left->left && !root->left->right)
        leftSum = root->left->val;
    else leftSum = sumOfLeftLeaves(root->left);
    rightSum = sumOfLeftLeaves(root->right);
    return leftSum + rightSum;
    // if(!root || (!root->left && !root->right)) 
    //     return 0;
    // if(root->left && root->right)
    //     return root->left->val +
    //      sumOfLeftLeaves(root->left)
    //       + sumOfLeftLeaves(root->right);
    // else if(!root->left)
    //     return sumOfLeftLeaves(root->right);
    // else 
    //      return root->left->val +
    //      sumOfLeftLeaves(root->left);
}

//=========================================================================================
//? 513. Find Bottom Left Tree Value
// Given the root of a binary tree, return the leftmost value in the last row of the tree.
//=========================================================================================
int   Solution::findBottomLeftValue(TreeNode* root)
{
    // if(!root) return 0;
    // std::queue<TreeNode*> q;
    // q.push(root);
    // int leftValue;
    // while(!q.empty()){
    //     std::size_t size = q.size();
    //     for(std::size_t i = 0; i < size; i++){
    //         TreeNode* node = q.front();
    //         if(i == 0)
    //             leftValue = node->val;
    //         q.pop();
    //         if(node->left)
    //             q.push(node->left);
    //         if(node->right)
    //             q.push(node->right);
    //     }
    // }
    // return leftValue;
    _MaxDepth = INT32_MIN;
    findBottomLeftValueRecursive(root, 0);
    return _MaxLeftValue;
}

void   Solution::findBottomLeftValueRecursive(TreeNode* root, int maxDepth){
    // firstly we should find the deepst layer, and then 
    // the first left node should be detected.

    if(root->left){
        maxDepth++;
        findBottomLeftValueRecursive(root->left, maxDepth);
        maxDepth--;
    }
    if(!root->left && !root->right){
    if(maxDepth > _MaxDepth){
            _MaxDepth = maxDepth;
            _MaxLeftValue = root->val;
        }
        return;
    }
    if(root->right){
        maxDepth++;
        findBottomLeftValueRecursive(root->right, maxDepth);
        maxDepth--;
    }
    return;
}

//=========================================================================================
// ? 112. Path Sum
// Given the root of a binary tree and an integer targetSum, 
// return true if the tree has a root-to-leaf path 
// such that adding up all the values along the path equals targetSum.
// A leaf is a node with no children.
//=========================================================================================
bool   Solution::hasPathSumI(TreeNode* root, int targetSum){
    return hasPathSumHelper(root, targetSum);
}
bool  Solution::hasPathSumHelper(TreeNode* root, int count){
    if(!root) return false;
    if(!root->left && !root->right && count - root->val == 0)
        return true;
    bool left = hasPathSumHelper(root->left, count - root->val);
    bool right  = hasPathSumHelper(root->right, count - root->val);
    return left || right;
}

bool  Solution::hasPathSumHelperIter(TreeNode* root, int count)
{
    if(!root) return false;
    std::stack<std::pair<TreeNode*, int> > st;
    st.push(std::make_pair(root, count - root->val));
    while(!st.empty()){
        auto node_pair = st.top();
        st.pop();
        if(!node_pair.first->left && !node_pair.first->right && node_pair.second == 0)
            return true;
        if(node_pair.first->right)
            st.push(std::make_pair(node_pair.first->right,
                node_pair.second - node_pair.first->right->val));
        if(node_pair.first->left)
            st.push(std::make_pair(node_pair.first->left, 
                node_pair.second - node_pair.first->left->val));
    }
    return false;
}
