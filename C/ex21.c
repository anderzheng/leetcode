/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *newList = l1, *pTail = NULL;
    
    if (NULL == l1)
    {
        return l2;
    }
    if (NULL == l2)
    {
        return l1;
    }
    if (l1->val > l2->val)
    {
        newList = l2;
        l2 = l2->next;
    }
    else
        l1 = l1->next;
    pTail = newList;

    while(l1 && l2)
    {
        if (l1->val < l2->val)
        {
            pTail->next = l1;
            l1 = l1->next;
        }
        else
        {
            pTail->next = l2;
            l2 = l2->next;
        }
        pTail = pTail->next;
    }
    if (l1 == NULL)
        pTail->next = l2;
    else
        pTail->next = l1;
    return newList;
}

