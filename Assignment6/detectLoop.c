/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    
    struct ListNode* fast=head,*slow=head;
    int count=0;
             if(fast==NULL||fast->next==NULL)
     return NULL;
while(fast!=NULL&&fast->next!=NULL)
{
    fast=fast->next->next;
    slow=slow->next;
    if(slow==fast)
    {
      count++;
        break;
    }
}
if(count!=0)
{if(slow==head)
    return head;
 else
 {
     slow=head;
     while(slow->next!=fast->next)
     {fast=fast->next;slow=slow->next;}
     return slow->next;
 }
}
 return NULL;
    
}