/************************************************************************
2.AddTwoNumbers
You are given two non-empty linked lists representing two non - negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input : (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output : 7 -> 0 -> 8
  Explanation : 342 + 465 = 807.
  * /
************************************************************************/

#include <iostream>
#include <forward_list>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * head = NULL, * tail = NULL;
    int carry = 0;
    while (l1 || l2 || carry)
    {
      int newValue = (l1?l1->val:0) + (l2?l2->val:0) + carry;
      carry = newValue / 10;
      newValue = newValue % 10;
      //new node
      ListNode * newNode = new ListNode(newValue);
      newNode->next = NULL;
      //
      if (head == NULL)
      {
        tail = newNode;
        head = tail;
      }
      else
      {
        tail->next = newNode;
        tail = tail->next;
      }
      //next
      l1 = l1 ? l1->next : NULL;
      l2 = l2 ? l2->next : NULL;

    }
    return head;
  }
};

ListNode * forward_list_to_C_list(const forward_list<int> & in)
{
  ListNode * head = NULL, *tail = NULL;
  for (int i : in)
  {
    ListNode * newNode = new ListNode(i);
    newNode->next = NULL;
    if (head == NULL)
    {
      tail = newNode;
      head = tail;
    }
    else
    {
      tail->next = newNode;
      tail = tail->next;
    }
  }
  return head;
}
forward_list<int> C_list_to_forward_list(ListNode * in)
{
  forward_list<int> result;
  forward_list<int>::iterator tail = result.before_begin();
  for (ListNode * index = in;index != NULL; index = index->next )
  {
    result.insert_after(tail, index->val);
    tail++;
  }
  return result;
}

int unitTest()
{
  Solution1 s1;
  forward_list<int> in1 = { 2,4,3 };
  ListNode * cin1 = forward_list_to_C_list(in1);
  forward_list<int> in2 = { 5,6,4 };
  ListNode * cin2 = forward_list_to_C_list(in2);
  forward_list<int> result = { 7,0,8 };
  ListNode * cmyResult = s1.addTwoNumbers(cin1, cin2);
  forward_list<int> myResult = C_list_to_forward_list(cmyResult);
  if (result == myResult)
  {
    cout << "Solution1 PASSED." << endl;
  }
  else
  {
    cout << "Solution1 FAILED." << endl;
  }
  delete cin1;
  delete cin2;
  delete cmyResult;

  return 0;
}