#include <iostream>
using namesapce std;

class ListNode
{
public:
  int val;
  ListNode *next;

};


//指针指向当前节点，判断和下一个节点是否相同（所以，当前节点和下一个节点不能为空）
//如果相同，则向后寻找不同点，再以此点继续判断

// 1.递归
ListNode *DelDupNode(ListNode* head)
{
  if(head==NULL) return NULL;
  if(head->next!=NULL && head->val == head->next->val)    //判断是否相同
	while(head->next!=NULL && head->val == head->next->val)    //找不相同的点
	  head = head->next;
	return DelDupNode(head->next);
  else
  	head->next = DelDupNode(head->next);

  return head;

}

// 2.非递归
ListNode *DelDupNode(ListNode* head)
{
  ListNode *pre = new ListNode(-1);
  ListNode *cur = pre;
  pre->next = head;
  while(cur->next!=NULL && cur->next->next!=NULL)
  {
      if(cur->next->val == cur->next->next->val)
      {
          ListNode *p = cur->next;
          while(p->next!=NULL && p->next->next!=NULL && p->val==p->next->val)
              p = p->next;
          cur->next = p;

      }
      else
      {
          cur = cur->next;

      }


  }
  
  return cur->next;
}
