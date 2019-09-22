/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* recursion method */
bool isSymmetricTree(struct TreeNode *t1, struct TreeNode *t2)
{
    if (t1 == NULL && t2== NULL)
        return true;
    if (t1 == NULL || t2 == NULL)
        return false;
    
    if (t1->val != t2->val)
        return false;
    else
        return isSymmetricTree(t1->left, t2->right) && isSymmetricTree(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root){
    
    
    if (NULL == root)
        return true;        // empty tree is symmetric
    
    return isSymmetricTree(root, root);

}

//-------------------------------------------------------------------------------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* iteratively method of DFS: passed 12ms */

bool isSymmetric(struct TreeNode* root){
    
    int s1 = 0, s2 = 0;
    struct TreeNode *ptr1 = NULL, *ptr2 = NULL;
    struct TreeNode *stack1[1000] = {NULL};
    struct TreeNode *stack2[1000] = {NULL};
    
    if (NULL == root)
        return true;        // empty tree is symmetric
       
    ptr1 = root->left;
    ptr2 = root->right;     /* if push root into stack, will cost 2 times */
    
    while(s1 > 0 || s2 > 0 || ptr1 != NULL || ptr2 != NULL)
    {
        /* push left node untill the depthest */
        while(ptr1)
        {
            stack1[s1++] = ptr1;
            ptr1 = ptr1->left;
        }
        /* push right node untill the depthest */
        while(ptr2)
        {
            stack2[s2++] = ptr2;
            ptr2 = ptr2->right;
        }
        
        if (s1 != s2)       /* not the same depth  */
        {
            return false;
        }
        
        /* pop the node to compare */
        ptr1 = (stack1[--s1]);
        ptr2 = (stack2[--s2]);

        if (ptr1->val != ptr2->val)
            return false;
        /* search from anther branch */
        ptr1 = ptr1->right;
        ptr2 = ptr2->left;
    }
    return true;

}
//=============================================================================================
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define  QUE_SIZE       1000

/* iteratively method of BFS */

bool isSymmetric(struct TreeNode* root){
    
    int head1 = 0, tail1 = 0, head2  = 0, tail2 = 0;
    struct TreeNode *ptr1 = NULL, *ptr2 = NULL;
    struct TreeNode *queue1[QUE_SIZE] = {NULL};
    struct TreeNode *queue2[QUE_SIZE] = {NULL};
    
    if (NULL == root)
        return true;        // empty tree is symmetric
       
    queue1[0] = root->left;
    queue2[0] = root->right;     /* if push root into stack, will cost 2 times */
    tail1 = tail2 = 1;
    
    while(tail1 != head1 || tail2 != head2)
    {
        if (tail1-head1 != tail2-head2) /* notice: the length may be diffrent between  queue1 and queue2 */
            return false;               /* without this check, line 41 will run error */
        
        /* get the first node from queue  */
        ptr1 = queue1[head1];
        head1 = (head1+1)%QUE_SIZE;
        
        ptr2 = queue2[head2];
        head2 = (head2+1)%QUE_SIZE;

        if (NULL == ptr1 && NULL == ptr2)
            continue;

        if (NULL == ptr1 || NULL == ptr2)
            return false;

        if (ptr1->val != ptr2->val) 
            return false;
        
        /* queue1 save from left to right */
        queue1[tail1] = ptr1->left;
        tail1 = (tail1+1)% QUE_SIZE;
        queue1[tail1] = ptr1->right;
        tail1 = (tail1+1)% QUE_SIZE;
        
        /* queue2 save from right to left */
        queue2[tail2] = ptr2->right;
        tail2 = (tail2+1)% QUE_SIZE;
        queue2[tail2] = ptr2->left;
        tail2 = (tail2+1)% QUE_SIZE;
    }
    return true;

}

