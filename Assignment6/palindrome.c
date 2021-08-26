/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if(head==NULL||head->next==NULL){return true;}
    struct ListNode* head1=head;
    struct ListNode* head2=head->next;
    int count=1;
    while(head1->next!=NULL){
        head1=head1->next;
        count++;
    }
    head1=head;
    head->next=NULL;
    for(int i=1;i<count/2;i++){
        struct ListNode* r=head2->next;
        head2->next=head1;
        head1=head2;
        head2=r;
    }
    if(count%2!=0){head2=head2->next;}
    while(head1!=NULL){
        if(head1->val!=head2->val){return false;}
        head1=head1->next;
        head2=head2->next;
    }
    return true;
    
}