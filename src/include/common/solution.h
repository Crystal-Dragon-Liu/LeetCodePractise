#ifndef SOLUTION_H
#define SOLUTION_H
#include "common/utils.h"
#include <unordered_set>
#include <math.h>
#include <queue>
#include <unordered_map>
#include <memory>
using TreeNodePtr = std::shared_ptr<TreeNode>;
class Solution
{
    public:
            //easy  141. linked list cycle
            bool                                hasCycle(ListNode* head);
            //normal 142.Linked List Cycle 2
            ListNode*                           detectCycle(ListNode *head);
            //easy
            bool                                containsDuplicate(std::vector<int>& nums);
            //easy
            int                                 singleNumber(std::vector<int>& nums);
            //easy
            std::vector<int>                    intersection(std::vector<int>& nums1, std::vector<int>& nums2);
            std::vector<int>                    get_intersection(const std::unordered_set<int>& set1, const std::unordered_set<int>& set2);
            //easy
            bool                                isHappy(int n);
            int                                 getNext(int n);
            //easy 19
            ListNode*                           getIntersectionNode(ListNode* headA, ListNode* headB);
            //normal
            ListNode*                           removeNthFromEnd(ListNode* head, int n);
            // easy
            ListNode*                           reverseList(ListNode* head);
            // easy
            ListNode*                           removeElements(ListNode* head, int val);
            // normal 328. Odd Even Linked List
            ListNode*                           oddEvenList(ListNode* head);
            // easy 234. Palindrome Linked List
            bool                                isPalindrome(ListNode* head);
            // normal 15. 3Sum
            std::vector<std::vector<int>>       threeSum(std::vector<int>& nums);
            // normal 144. Binary Tree Preorder Traversal
            std::vector<int>                    preorderTraversal(TreeNode* root);
            void                                preTraversal(TreeNode* root, std::vector<int>& data);
            // normal 94. Binary Tree Inorder Traversal
            std::vector<int>                    inorderTraversalII(TreeNode* root);
            std::vector<int>                    inorderTraversal(TreeNode* root);
            void                                inTraversal(TreeNode* root, std::vector<int>& data);
            // normal 145. Binary Tree Postorder Traversal
            std::vector<int>                    postorderTraversal(TreeNode* root);
            void                                postTraversal(TreeNode* root, std::vector<int>& data);
            // normal 102. Binary Tree Level Order Traversal
            std::vector<std::vector<int>>       levelOrder(TreeNode* root);
            // easy 104. Maximum Depth of Binary Tree
            int                                 maxDepth(TreeNode* root);
            int                                 maxDepthPostOrder(TreeNode* root);
            int                                 maxDepthLevelOrder(TreeNode* root);
            // 559. Maximum Depth of N-ary Tree
            int                                 maxDepth(NTree::Node* root);

            

            // easy 101. Symmetric Tree
            bool                                isSymmetric(TreeNode* root);
            bool                                check(TreeNode* p, TreeNode* q);
            bool                                checkV2(TreeNode* p, TreeNode* q);
            bool                                isSymmetricV2(TreeNode* root);
            // easy Given the root of a binary tree and an integer targetSum
            bool                                hasPathSum(TreeNode* root, int targetSum);
            // normal 106. Construct Binary Tree from Inorder and Postorder Traversal
            TreeNode*                           buildTree(std::vector<int>& inorder, std::vector<int>& postorder);
            TreeNode*                           buildTreeV2(std::vector<int>& inorder, std::vector<int>& postorder);
            TreeNode*                           buildTreeV2Helper(const std::vector<int>& preorder, 
            const std::vector<int>& inorder, 
            int preorder_left, 
            int preorder_right, 
            int inorder_left, 
            int inorder_right);
            TreeNode*                           helper(int in_left, int in_right, std::vector<int>& in_order, std::vector<int>& post_order);
            TreeNode*                           buildTreePreorderAndInorder(std::vector<int>& inorder, std::vector<int>& postorder);
            TreeNode*                           helperv2(const std::vector<int>& preorder, const std::vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right);

            // 105. Construct Binary Tree from Preorder and Inorder Traversal
            TreeNode*                           buildTreeV3(std::vector<int>& preorder, std::vector<int>& inorder);
            TreeNode*                           buildTreeV3Helper(std::vector<int>& preorder, 
            std::vector<int>& inorder,
            int preorder_left, int preorder_right,
            int inorder_left, int inorder_right);
            // normal 116. Populating Next Right Pointers in Each Node
            LabFor116::Node*                    connect(LabFor116::Node* root);
            // normal 117. Populating Next Right Pointers in Each Node II                                
            LabFor116::Node*                    connect_v2(LabFor116::Node* root);
            // easy 剑指 Offer 68 - II. 二叉树的最近公共祖先
            TreeNode*                           lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
            bool                                dfsForLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
            // hard 297. Serialize and Deserialize Binary Tree
            std::string                         serialize(TreeNode* root);
            TreeNode*                           deserialize(std::string data);
            TreeNode*                           parse(const std::string& data, int& ptr);
            int                                 parseInt(const std::string& data, int& ptr);
            TreeNode*                           parseSubtree(const std::string& data, int& ptr);
            // easy 100. Same Tree 
            bool                                isSameTree(TreeNode* p, TreeNode* q);
            // normal 96. Unique Binary Search Trees
            int                                 numTrees(int n);
            // easy 111. Minimum Depth of Binary Tre
            int                                 minDepth(TreeNode* root);
            int                                 minDepthRecursive(TreeNode* root);
            int                                 minDepthIterator(TreeNode* root);

            // easy 111. is balanced.
            bool                                isBalanced(TreeNode* root);
            int                                 height(TreeNode* root);
            // easy 108. Convert Sorted Array to Binary Search Tree
            TreeNode*                           sortedArrayToBST(std::vector<int>& nums);
            TreeNode*                           sortedArrayToBSTHelper(std::vector<int> & nums, int left, int right);
            //easy 257. Binary Tree Paths
            std::vector<std::string>            binaryTreePaths(TreeNode* root);
            std::vector<std::string>            binaryTreePathsIter(TreeNode* root);
            void                                buildPath(TreeNode* root, std::string path, std::vector<std::string>& pathList);
            // normal 95. Unique Binary Search Trees II
            std::vector<TreeNode*>              generateTrees(int n);
            std::vector<TreeNode*>              generateTrees(int start, int end);
            // normal 99. Recover Binary Search Tree
            void                                recoverTrees(TreeNode*);
            void                                getInorderVec(TreeNode*, std::vector<int>& num);
            std::pair<int, int>                 getTwoSwappedNodes(const std::vector<int>& num);         
            void                                searchTreeAndRecover(TreeNode*, int&, int, int);
            // normal 98. Validate Binary Search Tree
            bool                                isValidBST(TreeNode* root);
            bool                                isValidBSTHelper(TreeNode*, long long left, long long right);
            // normal 107. Binary Tree Level Order Traversal II
            std::vector<std::vector<int> >      levelOrderBottom(TreeNode* root);
            // normal 109. Convert Sorted List to Binary Search Tree
            TreeNode*                           sortedListToBST(ListNode* head);
            TreeNode*                           sortedListToBSTHelpler(ListNode* leftNode, ListNode* rightNode);
            ListNode*                           findMedianNode(ListNode* left, ListNode* right);
            // normal 113. Path Sum II
            std::vector<std::vector<int>>       pathSum(TreeNode* root, int targetSum);
            std::vector<std::vector<int>>       pathSumII(TreeNode* root, int targetSum);
            void                                pathSumIIHelperRecursive(TreeNode* root, 
                                                        std::vector<int>& path, std::vector<std::vector<int>>& result, int count);
            // easy 112. Path Sum
            bool                                hasPathSumI(TreeNode* root, int targetSum);
            bool                                hasPathSumHelper(TreeNode* root, int count);
            bool                                hasPathSumHelperIter(TreeNode* root, int count);

            void                                dfsPathSum(TreeNode* root, int targetSum);
            // normal 114. Flatten Binary Tree to Linked List
            void                                flatten(TreeNode* root);
            void                                preOrderTraversal(TreeNode* root, std::vector<TreeNode*>& treeNodeVec);

            // normal 129. Sum Root to Leaf Numbers
            int                                 sumNumbers(TreeNode* root);
            void                                sumNumbersHelper(TreeNode* root);
            int                                 calcBit(int num);
            // normal 199. Binary Tree Right Side View
            std::vector<int>                    rightSideView(TreeNode* root);
            // normal 300. Longest Increasing Subsequence
            int                                 lengthOfLIS(std::vector<int>& nums);

            // easy 53. Maximum Subarray
            int                                 maxSubArray(std::vector<int>& nums); 
            int                                 getSubArraySum(std::vector<int> vec);
            std::string                         getStrVec(std::vector<int>& nums);
            // normal 5. Longest Palindromic Substring
            std::string                         longestPalindrome(std::string s);
            // easy  509. Fibonacci Number
            int                                 fib(int n);
            // easy 70. Climbing Stairs
            int                                 climbStairs(int n); 
            int                                 climbStairsDP(int n, int m);

            // easy 746. Min Cost Climbing Stairs
            int                                 minCostClimbingStairs(std::vector<int>& cost);
            // normal 62. Unique Paths
            int                                 uniquePaths(int m, int n);
            // normal 63. Unique Paths II
            int                                 uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);
            // normal 343. Integer Break
            int                                 integerBreak(int n);
            // normal 416. Partition Equal Subset Sum
            bool                                canPartition(std::vector<int>& nums); 
            // normal 1049. Last Stone Weight II
            int                                 lastStoneWeightII(std::vector<int>& stones);
            // normal 494. Target Sum
            int                                 findTargetSumWays(std::vector<int>& nums, int target);
            // normal 474. Ones and Zeroes
            int                                 findMaxForm(std::vector<std::string>& strs, int m, int n);
            // normal 518. Coin Change 2
            int                                 change(int amount, std::vector<int>& coins);
            // normal 377. Combination Sum IV
            int                                 combinationSum4(std::vector<int>& nums, int target);
            // normal 322. Coin Change
            int                                 coinChange(std::vector<int>& coins, int amount);
            // 279. Perfect Squares
            int                                 numSquares(int n);
            // 139. Word Break
            bool                                wordBreak(std::string s, std::vector<std::string>& wordDict);
            // 198. House Robber
            int                                 rob(std::vector<int>& nums);
            // 213. House Robber II
            int                                 robII(std::vector<int>& nums);
            int                                 robRange(std::vector<int>& nums, int start, int end);
            // 337. House Robber III
            int                                 rob(TreeNode* root);
            std::vector<int>                    robTree(TreeNode* root);
            // 637. Average of Levels in Binary Tree
            std::vector<double>                 averageOfLevels(TreeNode* root);
            // 515. Find Largest Value in Each Tree Row
            std::vector<int>                    largestValues(TreeNode* root);
            // 226. Invert Binary Tree
            TreeNode*                           invertTree(TreeNode* root);
            TreeNode*                           invertTreeIterFront(TreeNode* root);
            TreeNode*                           invertTreeIterCommonFront(TreeNode* root);
            TreeNode*                           invertTreeLevelOrder(TreeNode* root);
            int                                 lengthOfLongestSubstring(std::string s);
            // 222. Count Complete Tree Nodes
            int                                 countNodesIteratorNormal(TreeNode* root);
            int                                 countNodes(TreeNode* root);
            int                                 countNodesRecursive(TreeNode* root);
            // the version according to properties of complete binary tree.
            int                                 countNodesRecursiveII(TreeNode* root);
            // 110. Balanced Binary Tree
            int                                 isBalancedBinaryTree(TreeNode* root);  
            int                                 isBalancedBinaryTreeIter(TreeNode* root);
            // 404. Sum of Left Leaves
            int                                 sumOfLeftLeaves(TreeNode* root);
            // 513. Find Bottom Left Tree Value
            int                                 findBottomLeftValue(TreeNode* root);
            void                                findBottomLeftValueRecursive(TreeNode* root, int maxLeft);
            // 654. Maximum Binary Tree
            TreeNode*                           constructMaximumBinaryTree(std::vector<int>& nums);
            TreeNode*                           constructMaximumBinaryTreeHelper(std::vector<int>& nums, std::size_t start, std::size_t end);
            
            // 617. Merge Two Binary Trees
            TreeNode*                           mergeTrees(TreeNode* root1, TreeNode* root2);


            // delete all the TreeNode ptr.
            void                                clearTreeNodes(){
                        std::size_t size = _TreeNodeVec.size();
                        std::cout << "delete nodes....." << std::endl;
                        for(std::size_t i = 0; i < size; i++){delete _TreeNodeVec[i];}
            }

    private:
            int                             post_index;
            std::unordered_map<int, int>    idx_map;
    public:
            TreeNode*                       ans;

            // 113. Path Sum II
            std::vector<std::vector<int> > _path_set;
            std::vector<int>               _path;
            // 129. path sum
            std::vector<int>               _sumPathSet;
            int                            _sumPath;

            // 513
            int                            _MaxLeftValue;
            int                            _MaxDepth;     
            // 106
            std::vector<TreeNode*>         _TreeNodeVec;
};
#endif