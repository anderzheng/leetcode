
/* using two point:passed: 12ms */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *pFast = NULL, *pSlow = NULL;
    
    if (NULL == head || NULL == head->next)
        return false;
    
    pSlow = head;
    pFast = head->next;
    while(NULL != pFast && pSlow!=pFast)
    {
        pSlow = pSlow->next;
        pFast = pFast->next;
        if (NULL != pFast)
        {
            pFast = pFast->next;
        }
        else
            break;
    }
    if (pSlow == pFast)
        return true;
    else
        return false;
}
