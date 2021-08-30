/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
if(head==NULL)
    return head;
    int len=1;
    struct ListNode* copyHead=head; 
    while(head->next!=NULL)
    {
      head=head->next;
        len++;
    }
    head->next=copyHead;
    head=copyHead;
    for(int i=((len-k)%len);i>1;i--)
    {
        head=head->next;
    }
    copyHead=head->next;
    head->next=NULL;
    return copyHead;
}