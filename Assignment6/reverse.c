/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
  struct ListNode* prev = NULL;
    struct ListNode* tmp = head;
    struct ListNode* bprev, *end, *beg, *lend;
    int i = 1;
    while (tmp != NULL) {
        struct ListNode* next = tmp->next;
        if (i == m) {
            bprev = prev;
            beg = tmp;
        }
        if (i == n) {
            end = tmp;
            lend = next;
        }
        if (i>=m && i<=n) {
            tmp->next = prev;
        }
        prev = tmp;
        tmp = next;
        i++;
    }
    if (bprev == NULL)
        head = end;
    else 
        bprev->next = end;
    
    beg->next = lend;
    
    return head;
}