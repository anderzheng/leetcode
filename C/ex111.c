/* passed: 8ms */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define         MAX_SIZE        1024

/* using BFS */
int minDepth(struct TreeNode* root){
    struct TreeNode*  queue[MAX_SIZE] = {NULL};
    struct TreeNode * pNode = NULL;
    int head = 0, tail = 0;
    int depth = 0, width = 0, i = 0;
    
    if (NULL == root)
    {
        return 0;
    }
    
    queue[0] = root;
    tail = 1;
    while(head != tail)
    {
        depth ++;
        width = (tail - head + MAX_SIZE)%MAX_SIZE;
        for(i=0; i<width; i++)
        {
            pNode = queue[head];
            head = (head+1)%MAX_SIZE;
            if (NULL == pNode->left && NULL == pNode->right)
            {
                return depth;
            }
            if (NULL != pNode->left)
            {
                queue[tail] = pNode->left;
                tail = (tail +1 )%MAX_SIZE;
            }
            if (NULL != pNode->right)
            {
                queue[tail] = pNode->right;
                tail = (tail +1 )%MAX_SIZE;
            }
        }
    }
    
    return depth;
}

