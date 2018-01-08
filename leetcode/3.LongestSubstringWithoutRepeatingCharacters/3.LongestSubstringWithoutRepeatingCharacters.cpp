/************************************************************************
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
************************************************************************/

#include <iostream>
using namespace std;

//brutal force
// O(n^3)
class Solution1 {
public:
  int lengthOfLongestSubstring(const string & s) 
  {
    if (s.size() <= 1) return s.size();
    int result = 1;
    for (unsigned int i = 0; i < s.size(); i++)
    {
      int tryLength = 2;
      for (unsigned int j = i+1; j < s.size(); j++)
      {
        bool duplicaed = false;
        for (unsigned int k = i; k < j; k++)
        {
          if (s[k] == s[j])
          {
            duplicaed = true;
            break;
          }
        }
        if (duplicaed == false)
        {
          if (result < tryLength)
          {
            result = tryLength;
          }
          tryLength++;
        }
        else
        {
          break;
        }
      }
    }
    return result;
  }
};

//slide window and character map
// O(n)
class Solution2 {
public:
  int lengthOfLongestSubstring(const string & s)
  {
    if (s.size() <= 1) return s.size();

    //use a array to store used characters.
    #define  ASCII_TABLE_SIZE 128
    int usedCharacterMap[ASCII_TABLE_SIZE] = {};

    int result = 1;
    //slide window [i, j)
    int i = 0, j = 1;
    usedCharacterMap[((int)(s[i]))] = 1;
    while (j < s.size())
    {
      if (usedCharacterMap[((int)(s[j]))] != 0)
      {
        usedCharacterMap[((int)(s[i]))] = 0;
        i++;
      }
      else
      {
        usedCharacterMap[((int)(s[j]))] = 1;
        j++;
        if (result < (j - i))
        {
          result = (j - i);
        }

      }
      if (i == j)
      {
        usedCharacterMap[((int)(s[j]))] = 1;
        j++;
      }
    }
    return result;
  }
};

int unitTest()
{
  Solution1 s1;
  if (s1.lengthOfLongestSubstring("abcabcbb") == 3)
  {
    cout << "solution 1, abcabcbb PASSED." << endl;
  }
  else
  {
    cout << "solution 1, abcabcbb FAILED." << endl;
  }
  if (s1.lengthOfLongestSubstring("bbbbb") == 1)
  {
    cout << "solution 1, bbbbb PASSED." << endl;
  }
  else
  {
    cout << "solution 1, bbbbb FAILED." << endl;
  }
  if (s1.lengthOfLongestSubstring("pwwkew") == 3)
  {
    cout << "solution 1, pwwkew PASSED." << endl;
  }
  else
  {
    cout << "solution 1, pwwkew FAILED." << endl;
  }

  Solution2 s2;
  if (s2.lengthOfLongestSubstring("abcabcbb") == 3)
  {
    cout << "solution 2, abcabcbb PASSED." << endl;
  }
  else
  {
    cout << "solution 2, abcabcbb FAILED." << endl;
  }
  if (s2.lengthOfLongestSubstring("bbbbb") == 1)
  {
    cout << "solution 2, bbbbb PASSED." << endl;
  }
  else
  {
    cout << "solution 2, bbbbb FAILED." << endl;
  }
  if (s2.lengthOfLongestSubstring("pwwkew") == 3)
  {
    cout << "solution 2, pwwkew PASSED." << endl;
  }
  else
  {
    cout << "solution 2, pwwkew FAILED." << endl;
  }


  return 0;
}