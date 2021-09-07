#include "gtest/gtest.h"
#include "common/utils.h"
#include "common/solution.h"

/*
** Test
** 1. Given the root of a binary tree, return its maximum depth.
** 2. Given the root of a binary tree, check whether it is a mirror of itself.
** 3. Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
*/ 

TEST(TreeEasyTest, DISABLED_Test1)
{
    //initialize a TreeNode List.
    TreeNode* root = new TreeNode(3, nullptr, nullptr);
    TreeNode* root_left_node = new TreeNode(9, nullptr, nullptr);
    TreeNode* root_right_node = new TreeNode(20, nullptr, nullptr);
    TreeNode* root_right_left_node = new TreeNode(15, nullptr, nullptr);
    TreeNode* root_right_right_node = new TreeNode(7, nullptr, nullptr);
    

    root->left = root_left_node;
    root_right_node->left = root_right_left_node;
    root_right_node->right = root_right_right_node;
    root->right = root_right_node;
    


    Solution solu;
    int result = solu.maxDepthLevelOrder(root);
    ASSERT_EQ(result, 3);
    delete root;
    delete root_left_node;
    delete root_right_node;
    delete root_right_right_node;
    delete root_right_left_node;
}

TEST(TreeEasyTest, DISABLED_Test2)
{
     //initialize a TreeNode List.
    TreeNode* root = new TreeNode(3, nullptr, nullptr);
    TreeNode* root_left_node = new TreeNode(9, nullptr, nullptr);
    TreeNode* root_right_node = new TreeNode(20, nullptr, nullptr);
    TreeNode* root_right_left_node = new TreeNode(15, nullptr, nullptr);
    TreeNode* root_right_right_node = new TreeNode(7, nullptr, nullptr);
    root->left = root_left_node;
    root_right_node->left = root_right_left_node;
    root_right_node->right = root_right_right_node;
    root->right = root_right_node;

    // check if the tree is symmetric.
    Solution solu;
    bool result = solu.isSymmetricV2(root);
    ASSERT_EQ(result, false);

    delete root;
    delete root_left_node;
    delete root_right_node;
    delete root_right_right_node;
    delete root_right_left_node;
}

TEST(TreeEasyTest, DISABLED_Test3)
{
     //initialize a TreeNode List.
    TreeNode* root = new TreeNode(3, nullptr, nullptr);
    TreeNode* root_left_node = new TreeNode(9, nullptr, nullptr);
    TreeNode* root_right_node = new TreeNode(20, nullptr, nullptr);
    TreeNode* root_right_left_node = new TreeNode(15, nullptr, nullptr);
    TreeNode* root_right_right_node = new TreeNode(7, nullptr, nullptr);
    root->left = root_left_node;
    root_right_node->left = root_right_left_node;
    root_right_node->right = root_right_right_node;
    root->right = root_right_node;

     // has path sum.
    Solution solu;
    bool result = solu.hasPathSum(root, 38);
    ASSERT_EQ(result, true);

    delete root;
    delete root_left_node;
    delete root_right_node;
    delete root_right_right_node;
    delete root_right_left_node;
}

TEST(TreeEasyTest, DISABLED_BinaryTreePathTest)
{
    //initialize a TreeNode List.
    TreeNode* root = new TreeNode(1, nullptr, nullptr);
    // left1, right1
    TreeNode* root_left_node = new TreeNode(2, nullptr, nullptr);
    TreeNode* root_right_node = new TreeNode(3, nullptr, nullptr);
    // left2, right2
    TreeNode* root_left_left_node = new TreeNode(4, nullptr, nullptr);
    TreeNode* root_left_right_node = new TreeNode(5, nullptr, nullptr);
    TreeNode* root_right_left_node = new TreeNode(6, nullptr, nullptr);
    TreeNode* root_right_right_node = new TreeNode(7, nullptr, nullptr);

    root->left = root_left_node;
    root->right = root_right_node;
    root_left_node->left = root_left_left_node;
    root_left_node->right = root_left_right_node;
    root_right_node->left = root_right_left_node;
    root_right_node->right = root_right_right_node;


    //-----------------------------------------------------------------
    Solution so;
    std::vector<std::string> result = so.binaryTreePathsIter(root);
    for(std::size_t i = 0; i < result.size(); i++)
        std::cout << "path: " << result[i] << std::endl;


    //-----------------------------------------------------------------
    // delete nodes.
    delete root;
    delete root_left_node;
    delete root_right_node;
    delete root_left_left_node;
    delete root_left_right_node;
    delete root_right_right_node;
    delete root_right_left_node;
}

TEST(TreeEasyTest, DISABLED_sumOfLeftLeavesTest)
{
    //initialize a TreeNode List.
    TreeNode* root = new TreeNode(1, nullptr, nullptr);
    // left1, right1
    TreeNode* root_left_node = new TreeNode(2, nullptr, nullptr);
    TreeNode* root_right_node = new TreeNode(3, nullptr, nullptr);
    // left2, right2
    TreeNode* root_left_left_node = new TreeNode(4, nullptr, nullptr);
    TreeNode* root_left_right_node = new TreeNode(5, nullptr, nullptr);
    TreeNode* root_right_left_node = new TreeNode(6, nullptr, nullptr);
    TreeNode* root_right_right_node = new TreeNode(7, nullptr, nullptr);

    root->left = root_left_node;
    root->right = root_right_node;
    root_left_node->left = root_left_left_node;
    root_left_node->right = root_left_right_node;
    // root_right_node->left = root_right_left_node;
    // root_right_node->right = root_right_right_node;


    //-----------------------------------------------------------------
    Solution so;
    int sum = so.sumOfLeftLeaves(root);
    std::cout << sum << std::endl;
    //-----------------------------------------------------------------
    // delete nodes.
    delete root;
    delete root_left_node;
    delete root_right_node;
    delete root_left_left_node;
    delete root_left_right_node;
    delete root_right_right_node;
    delete root_right_left_node;
}

TEST(TreeEasyTest, findBottomLeftValueTest)
{
    //initialize a TreeNode List.
    TreeNode* root = new TreeNode(1, nullptr, nullptr);
    // left1, right1
    TreeNode* root_left_node = new TreeNode(2, nullptr, nullptr);
    TreeNode* root_right_node = new TreeNode(3, nullptr, nullptr);
    // left2, right2
    TreeNode* root_left_left_node = new TreeNode(4, nullptr, nullptr);
    TreeNode* root_left_right_node = new TreeNode(5, nullptr, nullptr);
    TreeNode* root_right_left_node = new TreeNode(6, nullptr, nullptr);
    TreeNode* root_right_right_node = new TreeNode(7, nullptr, nullptr);

    root->left = root_left_node;
    root->right = root_right_node;
    root_left_node->left = root_left_left_node;
    root_left_node->right = root_left_right_node;
    // root_right_node->left = root_right_left_node;
    // root_right_node->right = root_right_right_node;


    //-----------------------------------------------------------------
    Solution so;
    int leftValue = so.findBottomLeftValue(root);
    std::cout << leftValue << std::endl;
    //-----------------------------------------------------------------
    // delete nodes.
    delete root;
    delete root_left_node;
    delete root_right_node;
    delete root_left_left_node;
    delete root_left_right_node;
    delete root_right_right_node;
    delete root_right_left_node;
}