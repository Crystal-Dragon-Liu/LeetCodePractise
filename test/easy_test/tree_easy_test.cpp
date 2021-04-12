#include "gtest/gtest.h"
#include "common/utils.h"
#include "common/solution.h"

/*
** Test
** 1. Given the root of a binary tree, return its maximum depth.
*/ 

TEST(TreeEasyTest, Test1)
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
    int result = solu.maxDepth(root);
    ASSERT_EQ(result, 3);
    // traverse the vector result and print it.
    // for(std::size_t i = 0; i < result.size(); i++)
    // {
    //     std::cout << "=======layer " << i << "=======" << std::endl;
    //     for(std::size_t j = 0; j < result[i].size(); j++)
    //     {
    //         std::cout << result[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }


    //delete each TreeNode.
    delete root;
    delete root_left_node;
    delete root_right_node;
    delete root_right_right_node;
    delete root_right_left_node;
}