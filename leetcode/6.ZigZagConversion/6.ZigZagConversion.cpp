/************************************************************************
6.ZigZagConversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line : "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows :

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//dive the whole string into groups.
/*
            group:         0   1    2    3
                         +------------------+
    P   A   H   N        |P  | A  | H  | N  |
    A P L S I I G  +---> |A P| L S| I I| G  |
    Y   I   R            |Y  | I  | R  |    |
                         +------------------+
*/
//scan the groups row by row and output the result;

class Solution {
public:
  string convert(string s, int numRows) 
  {
    if (numRows <= 1) return s;
    string result;
    //How many character in one  group;
    int groupSize = 2 * numRows - 2;
    //How many groups in current situation.
    int groupNumber = ceil((1.0 * s.size()) / groupSize);
    int index = 0;
    for (int i = 0; i < numRows; i++)
    {
      for (int j = 0; j < groupNumber; j++)
      {
        index = j* groupSize +i;
        if (index < s.size())
        {
          result += s[index];
        }
        if (i != 0 && i != numRows - 1)
        {
          index = ((j+1) * groupSize -i);
          if (index < s.size())
          {
            result += s[index];
          }
        }
      }
    }
    return result;
  }
};

int unitTest()
{
  Solution s1;
  if (s1.convert("PAYPALISHIRING",3) == "PAHNAPLSIIGYIR")
  {
    cout << "solution 1, PASSED." << endl;
  }
  else
  {
    cout << "solution 1, FAILED." << endl;
  }



  return 0;
}