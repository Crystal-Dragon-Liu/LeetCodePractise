#include "common/solution.h"
#include "common/utils.h"
#include <algorithm>
#include <math.h>
#include <stack>

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

std::vector<int>   Solution::inorderTraversalII(TreeNode* root)
{
    std::vector<int> result;
    std::stack<TreeNode*> st;
    if(root)
        st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        if(node != nullptr)
        {
        st.pop();
        if(node->right)
            st.push(node->right);

        st.push(node);
        st.push(nullptr);
        
        if(node->left)
            st.push(node->left);
        }
        else{
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
       
    }
    return result;
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

TreeNode* Solution::buildTreeV2(std::vector<int>& inorder, std::vector<int>& postorder){
    // the last element of  postorder vec must be the root of tree.
    if(inorder.size() == 0 || postorder.size() == 0)
        return nullptr;
    // split the postorder.
    // int root_value = postorder.back();
    // TreeNode* root = new TreeNode(root_value);
    // int index =0;
    // for(int i = 0; i < inorder.size(); i++)
    //     if(inorder[i] == root_value){
    //         index = i;
    //         break;
    //     }
    // root->left = buildTreeV2Helper(inorder, postorder);
    // root->right = buildTreeV2Helper(inorder, postorder);
    return buildTreeV2Helper(inorder, postorder, 0, postorder.size(), 0, inorder.size());
}

TreeNode*   Solution::buildTreeV2Helper(const std::vector<int>& inorder, 
            const std::vector<int>& postorder, 
            int postorder_left, 
            int postorder_right, 
            int inorder_left, 
            int inorder_right)
{
    // split the postorder.
    int root_value = postorder[postorder_right - 1];
    // SharedTreeNode::TreeNode root;
    TreeNode* root = new TreeNode(root_value);
    _TreeNodeVec.push_back(root);
    int index =0;
    for(int i = inorder_left; i < inorder_right; i++)
        if(inorder[i] == root_value){
            index = i; // 1
            break;
        }
    std::cout << "============= root: " << root_value << " detected ===============" << std::endl;
    int left_new_inorder_left = inorder_left; // 0
    int left_new_inorder_right = index; // 1

    int right_new_inorder_left = index+1; // 2
    int right_new_inorder_right = inorder_right; // 5

    int inorder_left_size = index - inorder_left ; // 1
    int inorder_right_size = inorder_right - index - 1; // 5 - 1 - 1 = 3

    int left_new_postorder_left = postorder_left; // 0 
    int left_new_postorder_right = postorder_left + inorder_left_size; //0 + 1 = 1

    int right_new_postorder_left = left_new_postorder_right; // 2
    int right_new_postorder_right = right_new_postorder_left + inorder_right_size; // 2 + 3 - 1 = 4

    if(right_new_inorder_left != right_new_inorder_right 
        && right_new_postorder_right != right_new_postorder_left)
        root->right = buildTreeV2Helper(inorder, postorder, 
                    right_new_postorder_left, 
                    right_new_postorder_right, 
                    right_new_inorder_left, 
                    right_new_inorder_right);
    if(left_new_postorder_left != left_new_postorder_right
        && left_new_inorder_left != left_new_inorder_right)
        root->left = buildTreeV2Helper(inorder, postorder, 
                    left_new_postorder_left, 
                    left_new_postorder_right, 
                    left_new_inorder_left, 
                    left_new_inorder_right);
    return root;
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

//============== 116. Populating Next Right Pointers in Each Node ========================
// You are given a perfect binary tree where all leaves are on the same level, 
// and every parent has two children.
// The binary tree has the following definition:
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
//=========================================================================================

LabFor116::Node*  Solution::connect(LabFor116::Node* root)
{
    if(!root) return nullptr;
    std::queue<LabFor116::Node*> q;
    q.push(root);
    while(!q.empty())
    {
        std::size_t size = q.size(); /// pop all the element to make sure that we could get all the nodes in same layer
        for(std::size_t i = 0; i < size; i++) /// record the size to make sure that we only tranverse one layer.
        {
            LabFor116::Node* node = q.front();
            q.pop();
            // connect.
            /// if the node is not the last one.
            if(i < size - 1) node->next = q.front(); 
            /// we could record nodes which belong to next layer without worry
            /// because in this loop, there is a restriction from the size we declared.
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right); 
        }
    }
    return root;
}


//============== 117. Populating Next Right Pointers in Each Node II ======================
// Given a binary tree
//
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node.
// If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.
//=========================================================================================

LabFor116::Node*            Solution::connect_v2(LabFor116::Node* root)
{
    
    if(!root) return nullptr;
    std::queue<LabFor116::Node*> q;
    q.push(root);
    while(!q.empty())
    {
            std::size_t size = q.size();
            LabFor116::Node *last = nullptr;
            for(std::size_t i = 0; i < size; i++)
            {
            LabFor116::Node* node = q.front();
            q.pop();
            /// expend elements on next layer.
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            /// connect start
            if(i != 0) last->next = node;
            last = node;
            /// connect
            }
    }
    return root;
}
//==============               96. Unique Binary Search Trees        ======================
// Given an integer n, 
//return the number of structurally unique BST's (binary search trees) 
// which has exactly n nodes of unique values from 1 to n.
//=========================================================================================

int    Solution::numTrees(int n)
{
    std::vector<int> G(n+1, 0);
    G[0] = 1;
    G[1] = 1;
    for(int i = 2; i <= n; i++){for(int j = 1; j <= i; j++){G[i] += G[j - 1] * G[i - j];}}
    return G[n];
}

//=========================================================================================
// ? 95. Unique Binary Search Trees II
// Given an integer n, 
// return all the structurally unique BST's (binary search trees), 
// which has exactly n nodes of unique values from 1 to n. 
// Return the answer in any order.
//=========================================================================================

std::vector<TreeNode*>  Solution::generateTrees(int n)
{
    if(!n) return {};
    return generateTrees(1, n);
}

std::vector<TreeNode*>  Solution::generateTrees(int start, int end)
{
    if(start > end) return std::vector<TreeNode*>{nullptr};
    std::vector<TreeNode*> allTree;
    for(int i = start; i <= end; i++)
    {
        std::vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
        std::vector<TreeNode*> rightTrees = generateTrees(i+1, end);
        for( auto leftTree: leftTrees)
            for(auto rightTree: rightTrees)
            {
                TreeNode* curNode = new TreeNode(i);
                curNode->left = leftTree;
                curNode->right = rightTree;
                allTree.emplace_back(curNode);
            }
    }
    return allTree;
}


//=========================================================================================
// ? 99. Recover Binary Search Tree
// You are given the root of a binary search tree (BST),
//  where exactly two nodes of the tree were swapped by mistake. 
//  Recover the tree without changing its structure.

// Follow up: A solution using O(n) space is pretty straight forward. 
// Could you devise a constant space solution?
//=========================================================================================
void            Solution::recoverTrees(TreeNode* node)
{
    // get a inorder vector that stands for the tree's value.
    std::vector<int> num;
    getInorderVec(node, num);
    // get the pair that contains the two node which need to be swapped.
    std::pair<int, int> x_y = getTwoSwappedNodes(num);
    int count = 2;
    searchTreeAndRecover(node, count, x_y.first, x_y.second);
}

void            Solution::getInorderVec(TreeNode* node, std::vector<int>& num)
{
    if(!node) return;
    getInorderVec(node->left, num);
    num.push_back(node->val);
    getInorderVec(node->right, num);
}



std::pair<int, int>  Solution::getTwoSwappedNodes(const std::vector<int>& nums)
{
        int n = nums.size();
        int x = -1, y = -1;
        for(int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] < nums[i]) {
                y = nums[i + 1];
                if (x == -1) {
                    x = nums[i];
                }
                else break;
            }
        }
        return {x, y};
}     

void Solution::searchTreeAndRecover(TreeNode* node, int& count, int x, int y)
{
    if(node)
    {
        if(node->val == x || node->val == y)
        {
            node->val = node->val == x ? y : x;
            if(--count == 0){return;}
            //?  make sure that we only swap val for 2 times.??
        }
        searchTreeAndRecover(node->left, count, x, y);
        searchTreeAndRecover(node->right, count, x, y);
    }
}

//=========================================================================================
// ?98. Validate Binary Search Tree
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
//=========================================================================================

bool Solution::isValidBST(TreeNode* root)
{
    return isValidBSTHelper(root, -99999, 99999);
}

bool Solution::isValidBSTHelper(TreeNode* root, long long left, long long right)
{
    if(root == nullptr) return true;
    if(root->val <= left || root->val >= right)
        return false;
    return isValidBSTHelper(root->left, left, root->val) && isValidBSTHelper(root->right, root->val, right);
    
}

//=========================================================================================
// ? 107. Binary Tree Level Order Traversal II
// Given the root of a binary tree, 
// return the bottom-up level order traversal of its nodes' values. 
// (i.e., from left to right, level by level from leaf to root).
//=========================================================================================

std::vector<std::vector<int> >  Solution::levelOrderBottom(TreeNode* root)
{
    std::vector<std::vector< int > > levelOrder;
    if(!root) return levelOrder;
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        auto level = std::vector<int>();
        int size = q.size();
        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        levelOrder.push_back(level);
    }
    std::reverse(levelOrder.begin(), levelOrder.end());
    return levelOrder;
}

//=========================================================================================
// ? 109. Convert Sorted List to Binary Search Tree
// Given the head of a singly linked list where elements are sorted in ascending order,
//  convert it to a height balanced BST.
// For this problem, 
// a height-balanced binary tree is defined as a binary tree
//  in which the depth of the two subtrees of every node never differ by more than 1.
//=========================================================================================

TreeNode*          Solution::sortedListToBST(ListNode* head)
{
    return sortedListToBSTHelpler(head, nullptr);
}

TreeNode*       Solution::sortedListToBSTHelpler(ListNode* leftNode, ListNode* rightNode)
{
    if(leftNode == rightNode) return nullptr;
    ListNode* node = findMedianNode(leftNode, rightNode);
    // build left sub-tree.
    TreeNode* rootNode = new TreeNode(node->val);
    rootNode->left = sortedListToBSTHelpler(leftNode, node);
    rootNode->right = sortedListToBSTHelpler(node->next, rightNode);
    return rootNode;
    // build right sub-tree.
}
ListNode*       Solution::findMedianNode(ListNode* left, ListNode* right)
{
    ListNode* fasterNode = left;
    ListNode* slowerNode = left;
    while(fasterNode != right && fasterNode->next != right)
    {
        fasterNode = fasterNode->next;
        fasterNode = fasterNode->next;
        slowerNode = slowerNode->next;
    }
    return slowerNode;
}



//=========================================================================================
// ? 113. Path Sum II
// Given the root of a binary tree and an integer targetSum, 
// return all root-to-leaf paths where each path's sum equals targetSum.
// A leaf is a node with no children.
//=========================================================================================
std::vector<std::vector<int>>   Solution::pathSum(TreeNode* root, int targetSum)
{
    dfsPathSum(root, targetSum);
    return _path_set;
}
// huisu
void                     Solution::dfsPathSum(TreeNode* root, int targetSum)
{
    if(!root) return;
    _path.push_back(root->val);
    targetSum -= root->val;
    if(!root->left && !root->right && targetSum == 0) // if the node is leaf node and there is a path in which each node ' value is the sum
    {
        _path_set.emplace_back(_path);
    }
    dfsPathSum(root->left, targetSum);
    dfsPathSum(root->right, targetSum);
    _path.pop_back(); // means that after the end of call of this method, path should be reset.
}

std::vector<std::vector<int>>       Solution::pathSumII(TreeNode* root, int targetSum){
    std::vector<std::vector<int>> result;
    if(!root) return result;
    std::vector<int> pathTemp;
    pathTemp.push_back(root->val);
    pathSumIIHelperRecursive(root, pathTemp, result, targetSum- root->val);
    return result;
}
void                                Solution::pathSumIIHelperRecursive(TreeNode* root, 
                                                        std::vector<int>& path, std::vector<std::vector<int>>& result, int count)
{
    if(!root->left && !root->right &&  count == 0){
        result.push_back(path);
    }
    if(root->left){
        path.push_back(root->left->val);
        pathSumIIHelperRecursive(root->left, path, result, count - root->left->val);
        path.pop_back();
    }
    if(root->right){
        path.push_back(root->right->val);
        pathSumIIHelperRecursive(root->right, path, result, count - root->right->val);
        path.pop_back();
    }
}



//=========================================================================================
// ? 114. Flatten Binary Tree to Linked List
// Given the root of a binary tree, flatten the tree into a "linked list":
// The "linked list" should use the same TreeNode class 
// where the right child pointer points to the next node in the list and the left child pointer
//  is always null.The "linked list" should be in the same order as a pre-order traversal of 
//  the binary tree.
//=========================================================================================
void                      Solution::flatten(TreeNode* root)
{
    std::vector<TreeNode*> treeNodeVec;
    preOrderTraversal(root, treeNodeVec);
    // TODO process  the treeNodeVec later.
    int n = treeNodeVec.size();
    for(int i = 1; i < n; i++)
    {
        TreeNode* cur_node = treeNodeVec.at(i - 1);
        TreeNode* next_node = treeNodeVec.at(i);
        cur_node->right = next_node;
        cur_node->left  = nullptr;
    }
}

void        Solution::preOrderTraversal(TreeNode* root, std::vector<TreeNode*>& treeNodeVec)
{
    if(!root) return;
    treeNodeVec.push_back(root);
    preOrderTraversal(root->left, treeNodeVec);
    preOrderTraversal(root->right, treeNodeVec);
}

//=========================================================================================
// ? 129. Sum Root to Leaf Numbers
// You are given the root of a binary tree containing digits from 0 to 9 only.
// Each root-to-leaf path in the tree represents a number.
// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. 
// Test cases are generated so that the answer will fit in a 32-bit integer.
// A leaf node is a node with no children.
//=========================================================================================
int        Solution::sumNumbers(TreeNode* root)
{
    _sumPath = 0;
    sumNumbersHelper(root);
    int result = 0;
    for(std::size_t i = 0; i < _sumPathSet.size(); i++){result += _sumPathSet[i];}
    return result;  
}

void       Solution::sumNumbersHelper(TreeNode* root)
{
    if(!root) return;
    // _sumPath += root->val;
    //TODO update the sum.
    // _sumPath += (root->val * pow(10, cnt));
    _sumPath = _sumPath* 10 + root->val;
    std::cout << _sumPath << std::endl;


    if(!root->left && !root->right){_sumPathSet.push_back(_sumPath);}
    sumNumbersHelper(root->left);
    sumNumbersHelper(root->right);
    //TODO reset the sum.
    _sumPath = (_sumPath - root->val) / 10;
    std::cout << _sumPath << std::endl;
}
int      Solution::calcBit(int num)
{
    int cnt = 0;
    while(num/10 != 0)
    {
        num = num/10;
        cnt++;
    }
    cnt += 1;
    return cnt;
}

//=========================================================================================
// ? 199. Binary Tree Right Side View
//Given the root of a binary tree, 
// imagine yourself standing on the right side of it, 
//return the values of the nodes you can see ordered from top to bottom.
//=========================================================================================
std::vector<int> Solution::rightSideView(TreeNode* root)
{
    std::vector<int> ret;
    std::vector<int> result;
    if(!root) return result;
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            ret.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result.push_back(ret.back());
        ret.clear();
    }
    return result;
}

//=========================================================================================
// ? 300. Longest Increasing Subsequence
// Given an integer array nums,
// return the length of the longest strictly increasing subsequence.
// A subsequence is a sequence that can be derived from an array by deleting some or no elements
// without changing the order of the remaining elements.
// For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
//=========================================================================================

int    Solution::lengthOfLIS(std::vector<int>& nums)
{
    std::vector<int> dp(nums.size(), 1);
    for(std::size_t i = 0; i < nums.size(); i++)
    {
        for(std::size_t j = 0; j < i; j++)
        {
            if(nums[j] < nums[i])
            {
                dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
    }
    return *(std::max_element(dp.begin(), dp.end()));
}
//=========================================================================================
// ? 53. Maximum Subarray
// Given an integer array nums, 
// find the contiguous subarray (containing at least one number) 
// which has the largest sum and return its sum.
// e.g. nums = [-2,1,-3,4,-1,2,1,-5,4]
//=========================================================================================

int Solution::maxSubArray(std::vector<int>& nums)
{
    std::vector<int> f(nums.size(), 0);
    for(std::size_t i = 0; i < nums.size(); i++)
    {
        int left = nums[i];
        int right = i!= 0 ? f[i-1] + nums[i]: nums[i];
        f[i] = std::max(right, left);
    }
    return *(std::max_element(f.begin(), f.end()));
    
}

int  Solution::getSubArraySum(std::vector<int> vec)
{
    int result = 0;
    for(std::size_t i = 0; i < vec.size(); i++)
        result += vec[i];
    return result;
}

std::string   Solution::getStrVec(std::vector<int>& nums)
{
    std::string result("");
    for(std::size_t i = 0; i < nums.size(); i++)
    {
        result += std::to_string(nums[i]);
        result += " ";
    }
    return result;
}
//=========================================================================================
// ? 5. Longest Palindromic Substrings
// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
// Example 3:

// Input: s = "a"
// Output: "a"
// Example 4:

// Input: s = "ac"
// Output: "a"
//=========================================================================================

std::string     Solution::longestPalindrome(std::string s)
{
    if(s.size() <2) return s; 
    std::vector<std::vector<bool> > dp(s.size(), std::vector<bool>(s.size(), true));
    // when i > j dp[i][j] == false;
    // when s[i] == s[j] && dp[i+1][j-1] == true, dp[i][j] == true.
    for(std::size_t i = 0; i < dp.size(); i++)
        dp[i][i] = true;
    int n = dp.size();
    int max = 1;
    std::string lpd;
    int begin = 0;
    // traverse the 
    for(int L = 2; L <= n; L++)
    {
        for(int i = 0; i < n; i++)
        {
            // traverse the array
            //[0 1] [1 2] [2 3] [3 4]...
            // [0 1 2] [1 2 3] ... 
            // [0 1 2 3] [1 2 3 4] ...
            int j = L -1 + i;
            if(j >= n) break;
            if(s[i] != s[j]) dp[i][j] = false;
            else{
                if(j - i < 3) dp[i][j] = true;
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            // if dp[i][j] == true, then record its length and compare it with max.
            if(dp[i][j] && j - i + 1 > max) 
            {
                    max = j - i + 1;
                    begin = i;
            }
        }
    }
    lpd = s.substr(begin, max);
    return lpd;
}
//=========================================================================================
// ? 222. Count Complete Tree Nodes
// Given the root of a complete binary tree, return the number of the nodes in the tree.

// According to Wikipedia, every level, except possibly the last,
// is completely filled in a complete binary tree, and all nodes in the last level are 
// as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

// Design an algorithm that runs in less than O(n) time complexity.
//=========================================================================================
int  Solution::countNodes(TreeNode* root){
    return countNodesIteratorNormal(root);
}


int  Solution::countNodesIteratorNormal(TreeNode* root)
{
    if(!root) return 0;
    std::queue<TreeNode*> queue;
    queue.push(root);
    int result = 0;
    while(!queue.empty()){
        std::size_t size = queue.size();
        for(std::size_t i = 0; i < size; i++){
            TreeNode* node = queue.front();
            queue.pop(); 
            result++;
            if(node->left)
                queue.push(node->left);
            if(node->right)
                queue.push(node->right);
        }
    }
    return result;
}

int  Solution::countNodesRecursiveII(TreeNode* root)
{
    if(!root) return 0;
    int leftDepth = 0;
    int rightDepth = 0;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    while(left){
        leftDepth++;
        left = left->left;
    }
    while(right){
        rightDepth++;
        right = right->right;
    }
    if(leftDepth == rightDepth)
        // util this layer, the tree could be recognized as a completed binary tree.
        return  (2 << leftDepth) -1;
    return countNodesRecursiveII(root->left) + countNodesRecursiveII(root->right) + 1;
}

int  Solution::countNodesRecursive(TreeNode* root)
{
if(!root) return 0;
    int leftNum = countNodesRecursive(root->left);
    int rightNum = countNodesRecursive(root->right);
    return leftNum + rightNum + 1;
}
