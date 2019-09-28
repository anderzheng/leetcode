/* passed: 8ms */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define     MAX_TREE_DEPTH      20
#define     MAX_BUFF      1000

void clearMem(int ** result, int size)
{
    int i = 0;
    for(;i< size; i++)
    {
        if (result[i] != NULL)
        {
            free(result[i]);
        }
    }
    free(result);
}

int ** levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    struct TreeNode * queue[MAX_BUFF] = {0};
    struct TreeNode *ptr = NULL;
    int head = 0, tail = 0, level = 0, size =0, i = 0;
    int **result = NULL;
    
    if (NULL == root)
    {
        *returnSize = 0;
        return NULL;
    }
    
    result = (int**)malloc(MAX_BUFF * sizeof(int*));
    if (NULL == result)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnColumnSizes = (int*)malloc(MAX_BUFF* sizeof(int));
    if (NULL == *returnColumnSizes)
    {
        *returnSize = 0;
        free(result);
        return NULL;
    }
    
    queue[0] = root;
    tail = 1;
    
    while(tail != head)
    {
        size = (tail-head+MAX_BUFF)%MAX_BUFF;
        (*returnColumnSizes)[level] = size;
        // malloc for this level
        result[level] = (int*)malloc(sizeof(int)*size);
        if (NULL == result[level])
        {
            clearMem(result, level);
            *returnSize = 0;
            return NULL;
        }
        
        i = 0;
        while(i < size)
        {
            ptr = queue[head];
            head = (head + 1)%MAX_BUFF;
            /* get the value */
            result[level][i++] = ptr->val;
            
            /* push the child to queue */
            if (ptr->left != NULL)
            {
                queue[tail] = ptr->left;
                tail = (tail+1)%MAX_BUFF;
            }
            if (ptr->right != NULL)
            {
                queue[tail] = ptr->right;
                tail = (tail+1)%MAX_BUFF;
            }
        }
        level ++;
    }
    
    *returnSize = level;
    return result;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **result = NULL, ** tmp = NULL;
    int *columnSizes = NULL;
    int i = 0, j=0, k=0;
    
    tmp = levelOrder(root, returnSize, &columnSizes);
    if (tmp == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
       
    result = (int **)malloc(*returnSize * sizeof(int*));
    if (NULL == result)
    {
        *returnSize = 0;
        clearMem(tmp, *returnSize);
        free(columnSizes);
        return NULL;        
    }
    
    /* notice: returnColumnSizes need to reverse order */
    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
    if (NULL == *returnColumnSizes)
    {
        *returnSize = 0;
        clearMem(tmp, *returnSize);
        free(columnSizes);
        free(result);
        return NULL;                
    }
    
    /* scan from bottom */
    for(i=*returnSize-1; i>=0; i--)
    {
        (*returnColumnSizes)[k] = columnSizes[i];
        result[k] = (int*)malloc(sizeof(int)*columnSizes[i]);
        if (NULL == result[k])
        {
            clearMem(tmp, *returnSize);
            free(columnSizes);
            clearMem(result, k);
            free(*returnColumnSizes);
            *returnSize = 0;
            return NULL;
        }
        
        /* copy the level */
        for(j=0; j<columnSizes[i]; j++)
        {
            result[k][j] = tmp[i][j];
        }
        
        /* next level */
        k++;
    }
    
    /* free */
    clearMem(tmp, *returnSize);
    free(columnSizes);

    return result;
}

