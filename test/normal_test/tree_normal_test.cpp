#include "gtest/gtest.h"
#include "common/utils.h"
#include "common/solution.h"

/*
** Test
**  1. Given the root of a binary tree, return the preorder traversal of its nodes' values.
*/
TEST(TreeNormalTest, Test1)
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