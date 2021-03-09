#include "common/solution.h"
// Given an integer array nums, 
// return true if any value appears at least twice in the array, 
// and return false if every element is distinct.

bool Solution::containsDuplicate(std::vector<int>& nums)
{
        return nums.size() > std::unordered_set<int>(nums.begin(), nums.end()).size();
}


// Given a non-empty array of integers nums, every element appears twice except for one. 
//Find that single one.
// Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?

int Solution::singleNumber(std::vector<int>& nums)
{
    int answer;
    std::unordered_set<int> bobo;
    for(auto i: nums)
    {
        if(bobo.count(i)) bobo.erase(i);
        else{
            bobo.insert(i);
        }
    }
    for(auto j: bobo)
    {
        answer = j;
    }
    return answer;
}

std::vector<int> Solution::intersection(std::vector<int>& nums1, std::vector<int>& nums2)
{
    // the first solution.
    // m is the length of larger vector, n is the size of smaller vector.
    // we could traverse the vector with size n
    // to find out if the elements in vector with size n are also in the vector with size m.
    // but if we directly use vector, it would risk O(m*n)
    // so the solution is to build two HashSet to re initialize these vector input,
    // which enable us to traverse the elements with O(1).
    
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());
    return get_intersection(set1, set2);
}

std::vector<int> Solution::get_intersection(const std::unordered_set<int>& set1, const std::unordered_set<int>& set2)
{
    //find out the set with largest vector.
    if(set2.size() < set1.size())
        return get_intersection(set2, set1);
    else
    {
        std::vector<int> result;
        // if there is a element which is also in the other set, then we should
        // insert this element into result which is a new HashSet we declared.
        std::unordered_set<int>::const_iterator iter = set1.begin();
        for(;iter != set1.end(); iter++)
        {
            if(set2.count(*iter))
                result.push_back(*iter);
        }
        return result;
    }
}
int Solution::getNext(int n)
{
    int total_num = 0;
    std::vector<int> split_result;
    split_result = splitInt(n);
    if(n < 0) return total_num;
    for(size_t i = 0; i < split_result.size(); i++)
    {
        total_num += pow(split_result[i], 2);
    }
    return total_num;

}


bool Solution::isHappy(int n)
{
    std::unordered_set<int> set;
    while(n != 1 && !set.count(n))
    {
        set.insert(n);
        n = getNext(n);
    }
    return n == 1 ? true: false;
}