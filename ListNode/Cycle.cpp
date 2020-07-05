//如果有环，找到入环的节点

#include <iostream>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

};

//设置快慢指针，快指针每次比慢指针多走一步，如果有环，那么两指针肯定会在一点相遇
//并且这点到入环点的距离和链表起始点的距离相同
ListNode *Cycle(ListNode *head)
{
  ListNode *fast = head;
  ListNode *slow = head;
  while(fast != NULL && fast->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;
    if(fast == slow)
    {
      break;
    }
  }
  if((fast == NULL) || (fast->next == NULL))
    return NULL;
  while(head != slow)
  {
    head = head->next;
    slow = slow->next;
  }

  return head;

}