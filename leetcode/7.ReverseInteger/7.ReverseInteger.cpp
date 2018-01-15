/************************************************************************
7.ReverseInteger
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows. 
************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  inline bool isNextStepOverFlow(int tmp)
  {
    if (tmp > 0 && tmp > INT_MAX / 10) return true;
    if (tmp < 0 && tmp < INT_MIN / 10) return true;
    return false;
  }
  int reverse(int x) 
  {
    int  result = 0;
    int tmp = 0;
    while (x != 0)
    {
      tmp = x % 10;
      result += tmp;
      x = x / 10;
      if (x != 0)
      {
        if (isNextStepOverFlow(result)) return 0;
        result *= 10;
      }
    }
    
    return result;
  }
};

int unitTest()
{
  Solution s1;
  if (s1.reverse(123) == 321)
  {
    cout << "solution 1, PASSED." << endl;
  }
  else
  {
    cout << "solution 1, FAILED." << endl;
  }
  if (s1.reverse(-123) == -321)
  {
    cout << "solution 2, PASSED." << endl;
  }
  else
  {
    cout << "solution 2, FAILED." << endl;
  }
  if (s1.reverse(120) == 21)
  {
    cout << "solution 3, PASSED." << endl;
  }
  else
  {
    cout << "solution 3, FAILED." << endl;
  }
  if (s1.reverse(1534236469) == 0)
  {
    cout << "solution 4, PASSED." << endl;
  }
  else
  {
    cout << "solution 4, FAILED." << endl;
  }

  if (s1.reverse(-2147483412) == -2143847412)
  {
    cout << "solution 5, PASSED." << endl;
  }
  else
  {
    cout << "solution 5, FAILED." << endl;
  }
  return 0;
}