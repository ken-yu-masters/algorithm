/************************************************************************
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Example:

Input: "cbbd"

Output: "bb"
************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//brutal force
//O(n^2)
class Solution1 {
public:
	string longestPalindrome(string s)
	{
        if (s.empty()) return s;
        int retLength=1;
		int retPos=0;
		int tryLength, i0, i1;
		for (int i = 0; i < s.size(); i++)
		{
			tryLength = 3;
			i0 = i - 1, i1 = i + 1;
			while (i0 >= 0 && i1 < s.size())
			{
				if (s[i0] == s[i1])
				{
					if (tryLength > retLength)
					{
						retLength = tryLength;
						retPos = i0;
					}
					tryLength += 2;
					i0--;
					i1++;
				}
                else
                {
                    break;
                }
			}
			tryLength = 2;
			i0 = i; i1 = i + 1;
			while (i0 >= 0 && i1 < s.size())
			{
				if (s[i0] == s[i1])
				{
					if (tryLength > retLength)
					{
						retLength = tryLength;
						retPos = i0;
					}
					tryLength += 2;
					i0--;
					i1++;
				}
                else
                {
                    break;
                }
			}
		}
		return s.substr(retPos,retLength);
	}
};

//https://www.felix021.com/blog/read.php?2040
//Manacher's ALGORITHM
//O(n)
class Solution2 {
public:
  //make the code can deal with even/odd substring at same time.
  string preprocess(string s)
  {
    //"$" and "@" is special string which cannot appear in string s
    string result = "$#";
    for (int i = 0; i < s.size(); i++)
    {
      result = result + s[i] + "#";
    }
    result += "@";
    return result;
  }
  string longestPalindrome(string s)
  {
    string translateString = preprocess(s);
    vector<int> P;//try length.
    P.resize(translateString.size());
    std::fill(P.begin(), P.end(), 1);
    int id = 1, mx = 1,j;
    for ( int i =1; i<translateString.size()-1; i++)
    {
      j = id - (i - id);
      P[i] = mx > i ? std::min(P[j], (mx - i)) : 1;
      while (translateString[i + P[i]] == translateString[i - P[i]])
      {
        P[i]++;
      }
      if (i + P[i] > mx) 
      {
        mx = i + P[i];
        id = i;
      }
    }

    //find the result position
    int maxLen = 0;
    int maxPos = 0;
    for (int i = 1; i < P.size() - 1; i++)
    {
      if (P[i] > maxLen) 
      {
        maxLen = P[i]-1;
        maxPos = i;
      }
    }
    //translate back to original s position
    maxPos = ((maxPos - maxLen  -1 ) / 2);
    //
    return s.substr(maxPos, maxLen);
  }
};
int unitTest()
{
  Solution2 s1;
  if (s1.longestPalindrome("babad") == "bab")
  {
    cout << "solution 1, abcabcbb PASSED." << endl;
  }
  else
  {
    cout << "solution 1, abcabcbb FAILED." << endl;
  }
    if (s1.longestPalindrome("cbbd") == "bb")
  {
    cout << "solution 1, abcabcbb PASSED." << endl;
  }
  else
  {
    cout << "solution 1, abcabcbb FAILED." << endl;
  }


  return 0;
}