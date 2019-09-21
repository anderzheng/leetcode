/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* passed 8ms */
/* just practise the operation of list */
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* pPrev = NULL, *pNext = NULL;
    
    if (NULL == head)
        return NULL;
    pPrev = head;
    pNext = head->next;
    while(pNext)
    {
        if (pPrev->val == pNext->val)
        {
            pPrev->next = pNext->next;
            free(pNext);
            pNext = pPrev->next;
        }
        else
        {
            pPrev = pNext;
            pNext = pNext->next;
        }
    }
    
    return head;
}

