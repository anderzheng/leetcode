/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* using iteratively method */

#define     MAX_SIZE    1000
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    struct TreeNode * buff[MAX_SIZE] = {NULL}, *ptr = NULL;
    int head = 0, tail = 0;
    int i = 0, rows = 0, cols = 0;
    int **result = NULL;
    
    if (NULL == root)
        return NULL;
    
    result = (int**)malloc(sizeof(int*) * MAX_SIZE);
    if(NULL == result)
    {
        return NULL;
    }
    *returnColumnSizes = (int*)malloc(sizeof(int)*MAX_SIZE);
    if (NULL == *returnColumnSizes)
    {
        free(result);
        free(*returnColumnSizes);
        return NULL;
    }
    buff[0] = root;
    tail = 1;
    
    while(tail != head)
    {
        cols = (tail - head + MAX_SIZE)%MAX_SIZE;
        *returnColumnSizes[rows] = cols;
        result[rows] = (int*)malloc(sizeof(int)*cols);
        if (NULL == result[rows])
        {
            free(result);
            free(*returnColumnSizes);
            return NULL;
        }
        
        for(i=0; i<cols; i++)
        {
            ptr = buff[head];
            head = (head+1)%MAX_SIZE;
            result[rows][i] = ptr->val;         // save the level data
            
            /* push the next level to buff */
            if (ptr->left != NULL)
            {
                buff[tail] = ptr->left;
                tail = (tail +1)%MAX_SIZE;
            }
            if (ptr->right != NULL)
            {
                buff[tail] = ptr->right;
                tail = (tail +1)%MAX_SIZE;
            }
        }
        rows ++;
    }
    *returnSize = rows;
    
    return result;
}

