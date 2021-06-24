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