/********************************************************************************************************
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
----------------------------------------------------------------------------------------------------------
Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
********************************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//brutal force crack
//O(n^2)
class Solution_1 {
public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = 0; j < nums.size(); j++)
      {
        if (i == j) continue;
        if (nums[i] + nums[j] == target)
        {
          vector<int> ret;
          ret.push_back(i);
          ret.push_back(j);
          return ret;
        }
      }
    }
    return vector<int>();
  }
};

//use a hash table to increase speed
//O(n)
class Solution_2 {
public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++)
    {
      numMap.emplace(nums[i], i);
    }
    for (int i = 0; i < nums.size(); i++)
    {
      int complement = target - nums[i];
      if (numMap.find(complement) != numMap.end())
      {
        vector<int> ret;
        ret.push_back(i);
        ret.push_back(numMap[complement]);
        return ret;
      }
    }
    return vector<int>();
  }
};

//merge the first loop of construct hash table to second loop.
//O(n)
class Solution_3 {
public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++)
    {
      int complement = target - nums[i];
      if (numMap.find(complement) != numMap.end())
      {
        vector<int> ret;
        ret.push_back( (i<= numMap[complement]) ? i : numMap[complement]);
        ret.push_back( (i > numMap[complement]) ? i : numMap[complement]);
        return ret;
      }
      numMap.emplace(nums[i], i);
    }
    return vector<int>();
  }
};


int unitTest()
{
  vector<int> nums = { 2, 7, 11, 15 };
  int target = 9;
  vector<int> ret = { 0,1 };

  Solution_1 s1;
  if (ret == s1.twoSum(nums, target))
  {
    cout << "solution_1 PASSED." << endl;
  }
  else
  {
    cout << "solution_1 FAILED." << endl;

  }
  Solution_2 s2;
  if (ret == s2.twoSum(nums, target))
  {
    cout << "solution_2 PASSED." << endl;
  }
  else
  {
    cout << "solution_2 FAILED." << endl;
  }
  Solution_3 s3;
  if (ret == s3.twoSum(nums, target))
  {
    cout << "solution_3 PASSED." << endl;
  }
  else
  {
    cout << "solution_3 FAILED." << endl;
  }
  return 0;
}
