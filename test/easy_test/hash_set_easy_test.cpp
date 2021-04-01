#include "common/utils.h"
#include "gtest/gtest.h"
#include "common/config.h"
#include "common/solution.h"
class MyHashSet;
#define INVALUE_RETURN_VALUE -9999
Solution solution_test;
std::vector<std::string> load_method_name_from_csv(const std::string& path)
{
    std::ifstream in_file(path, std::ios::in);
    // std::vector<std::vector<std::string> > result;
    std::vector<std::string> result;
    std::string lineStr;
    while(getline(in_file, lineStr))
    {
        result.push_back(lineStr);
    }
    return result;
}

std::vector<std::vector<int> > load_input_data_from_csv(const std::string& path)
{
    std::ifstream in_file(path, std::ios::in);
    std::vector<std::vector<int> > result;
    std::vector<int> result_temp;
    std::string lineStr;
    while(getline(in_file, lineStr))
    {
        std::stringstream ss(lineStr);
        std::string str;
        while(getline(ss, str, ','))
        {
            result_temp.push_back(stringToTp<int>(str));
        }
        result.push_back(result_temp);
        result_temp.clear();
    }
    return result;
}

std::vector<int> run_method(MyHashMap& hash_map, const input_list_int& input, const func_list& method)
{
    std::vector<int> result;
    for(size_t i = 0; i < input.size(); i++)
    {
        if(method[i] == "put")
        {
            // std::cout << "put the ("  << input[i][0] << ", " << input[i][1] << ") into hash map" << std::endl;
            hash_map.put(input[i][0], input[i][1]);
            result.push_back(INVALUE_RETURN_VALUE);
        }
        if(method[i] == "get")
        {
            int value = hash_map.get(input[i][0]);
            result.push_back(value);
            // std::cout << "get key:" << input[i][0] << ", and result is " << value << std::endl;
        }
        if(method[i] == "remove")
        {
            result.push_back(INVALUE_RETURN_VALUE);
            // std::cout << "remove " << input[i][0] << std::endl;
            hash_map.remove(input[i][0]);
        }
        // hash_map.print_all_buckets();
        // std::cout << "this is " << i << "method" << std::endl;
        }
    return result;

}

TEST(MyHashSetBasicTest, DISABLE_Test1)
{
    MyHashSet my_hash_set;
    my_hash_set.add(1);
    my_hash_set.add(2);
    EXPECT_EQ(true, my_hash_set.contains(1));
    EXPECT_EQ(false, my_hash_set.contains(3));
    my_hash_set.add(2);
    EXPECT_EQ(true, my_hash_set.contains(2)); 

    my_hash_set.remove(2);   
    // my_hash_set.print_all_buckets();
    my_hash_set.remove(1);
}



TEST(MyHashSetBasicTest, DISABLE_Test2)
{
    // load the method name.
    std::string method_path("../../../test_data/call_method.csv");
    std::vector<std::string> call_method;
    call_method = load_method_name_from_csv(method_path);
    EXPECT_EQ(110, call_method.size());
    // load the input data.
    std::string input_path("../../../test_data/input_data.csv");
    std::vector<std::vector<int> > input_data;
    input_data = load_input_data_from_csv(input_path);
    
    EXPECT_EQ(110, input_data.size());
    MyHashMap my_hash_map;
    std::vector<int> result = run_method(my_hash_map, input_data, call_method);
}

TEST(MyHashSetBasicTest, DISABLE_Test3)
{
    std::vector<int> nums{4, 3, 5, 3, 5};
    Solution solu;
    EXPECT_EQ(4, solu.singleNumber(nums));
}

TEST(MyHashSetBasicTest, DISABLE_Test4)
{
    std::vector<int> nums1{4, 9, 5};
    std::vector<int> nums2{9, 4, 9, 8, 4};
    std::vector<int> result = solution_test.intersection(nums1, nums2);
    for(size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }
}

// delete the fourth-to-last LinkedNode.

TEST(MyHashSetBasicTest, Test5)
{
    
}