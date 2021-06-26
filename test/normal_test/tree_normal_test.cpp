#include "gtest/gtest.h"
#include "common/utils.h"
#include "common/solution.h"

/*
** Test
**  1. Given the root of a binary tree, return the preorder traversal of its nodes' values.
**  2. Given the root of a binary tree, return the inorder traversal of its nodes' values.
**  3. Given the root of a binary tree, return the postorder traversal of its nodes' values.
**  4. Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
*/
TEST(TreeNormalTest, DISABLED_Test1)
{
    //initialize a TreeNode List.
    TreeNode* root = new TreeNode(1, nullptr, nullptr);
    TreeNode* root_left_node = new TreeNode(2, nullptr, nullptr);
    TreeNode* root_right_node = new TreeNode(3, nullptr, nullptr);

    root->left = root_left_node;
    root->right = root_right_node;
    Solution solu;
    auto result = solu.preorderTraversal(root);
    // traverse the vector result and print it.
    std::vector<int>::iterator iter = result.begin();
    std::cout << "====print the nodes====" << std::endl;
    for(; iter != result.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    //delete each TreeNode.
    delete root;
    delete root_left_node;
    delete root_right_node;
}

TEST(TreeNormalTest, DISABLED_Test2)
{
    //initialize a TreeNode List.
    TreeNode* root = new TreeNode(1, nullptr, nullptr);
    TreeNode* root_left_node = new TreeNode(2, nullptr, nullptr);
    TreeNode* root_right_node = new TreeNode(3, nullptr, nullptr);
    root->left = root_left_node;
    root->right = root_right_node;


    Solution solu;
    auto result = solu.inorderTraversal(root);
    // traverse the vector result and print it.
    std::vector<int>::iterator iter = result.begin();
    std::cout << "====print the nodes====" << std::endl;
    for(; iter != result.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    //delete each TreeNode.
    delete root;
    delete root_left_node;
    delete root_right_node;
}

TEST(TreeNormalTest, DISABLED_Test3)
{
    //initialize a TreeNode List.
    TreeNode* root = new TreeNode(1, nullptr, nullptr);
    TreeNode* root_left_node = new TreeNode(2, nullptr, nullptr);
    TreeNode* root_right_node = new TreeNode(3, nullptr, nullptr);
    root->left = root_left_node;
    root->right = root_right_node;


    Solution solu;
    auto result = solu.postorderTraversal(root);
    // traverse the vector result and print it.
    std::vector<int>::iterator iter = result.begin();
    std::cout << "====print the nodes====" << std::endl;
    for(; iter != result.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    //delete each TreeNode.
    delete root;
    delete root_left_node;
    delete root_right_node;
}

TEST(TreeNormalTest, DISABLED_Test4)
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
    auto result = solu.levelOrder(root);
    // traverse the vector result and print it.
    for(std::size_t i = 0; i < result.size(); i++)
    {
        std::cout << "=======layer " << i << "=======" << std::endl;
        for(std::size_t j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }


    //delete each TreeNode.
    delete root;
    delete root_left_node;
    delete root_right_node;
    delete root_right_right_node;
    delete root_right_left_node;
}

TEST(TreeNormalTest, DISABLED_Test5)
{
    TreeNode* root_right = new TreeNode(3, nullptr, nullptr);
    TreeNode* root = new TreeNode(1, nullptr, nullptr);
    TreeNode* root_left = new TreeNode(2, nullptr, nullptr);
    root->left = root_left;
    root->right = root_right;
    Solution solu;
    int result = solu.sumNumbers(root);
    std::cout << result << std::endl;
    delete root->left;
    delete root->right;
    delete root;
}

TEST(TreeNormalTest, DISABLED_Test6)
{
    TreeNode* node1 = new TreeNode(1, nullptr, nullptr);
    TreeNode* node2 = new TreeNode(2, nullptr, nullptr);
    TreeNode* node3 = new TreeNode(3, nullptr, nullptr);
    TreeNode* node4 = new TreeNode(4, nullptr, nullptr);
    TreeNode* node5 = new TreeNode(5, nullptr, nullptr);

    node1->left = node2;
    node1->right = node3;
    node2->right = node5;
    node3->right = node4;
    Solution solu;
    std::vector<int> result = solu.rightSideView(node1);
    for(std::size_t i = 0; i < result.size(); i++)
        std::cout << result[i] << std::endl;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

}

TEST(TreeNormalTest, Test7)
{
    std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution solu;
    int result = solu.maxSubArray(nums);
    std::cout << result << std::endl;
}