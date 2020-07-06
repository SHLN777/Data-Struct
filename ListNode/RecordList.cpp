
//给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
//将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

#include <iostream>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

};

void RecordList(ListNode *head)
{
    if(head == NULL)  return;
    ListNode *fast=head, *slow=head;  //快慢指针，寻找中间节点
    while(fast->next)
    {
        fast = fast->next;
        slow = slow->next;
        if(fast->next)
            fast = fast->next;
        
    }
    ListNode *cur = slow->next, *r;
    slow->next = NULL;
    while(cur)
    {
        r = cur->next;
        cur->next = slow->next;
        slow->next = cur;
        cur = r;
    }
    ListNode *f = head;
    cur = slow->next;
    slow->next = NULL;
    while(cur)
    {
        r = cur->next;
        cur->next = f->next;
        f->next = cur;
        cur = r;
    }
}