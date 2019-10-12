
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* using recursively: passed 8ms */

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *ptr = NULL;
    
    if (head == NULL || head->next == NULL)
        return head;
    ptr = reverseList(head->next);
    
    head->next->next = head;        // reverse n and n+1 node
    head->next = NULL;      // notice: will be circle if not set null
    return ptr;
}

#if 0
/* using iteratively: 0ms passed */

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = NULL, *next = NULL;
    
    prev = NULL;
   
    while(head != NULL)// && head->next != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}
#endif
