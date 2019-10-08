/* passed: 16ms */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *prevPtr = NULL, *currPtr = NULL;
    
    while(head != NULL && head->val == val)
    {
        prevPtr = head;
        head = head->next;
        free(prevPtr);
    }
    if (head == NULL)
        return NULL;
    
    prevPtr = head;
    currPtr = head->next;
    while(NULL != currPtr)
    {
        if(currPtr->val == val)
        {
            prevPtr->next = currPtr->next;
            free(currPtr);
        }
        else
        {
            prevPtr = currPtr;
        }
        currPtr = prevPtr->next;
    }
    
    return head;
}

