/* passed: 0ms */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int i=0, j=0;
    int ** result = NULL;
    
    if (numRows == 0)
    {
        *returnSize = 0;
        return NULL;
    }
        
    result = (int**)malloc(sizeof(int*)*numRows);
    if (NULL == result)
    {
        *returnSize = 0;
        return NULL;        
    }
    *returnColumnSizes = (int*)malloc(sizeof(int)*numRows);
    if (NULL == result)
    {
        free(result);
        *returnSize = 0;
        return NULL;        
    }
    
    *returnSize = numRows;
    for(i=0; i<numRows; i++)
    {
        (*returnColumnSizes)[i] = i+1;
        result[i] = (int*)malloc(sizeof(int)*(i+1));
        if (NULL == result[i])
        {
            for(j=0; j<i; j++)
                free(result[j]);
            free(result);
            free(*returnColumnSizes);
            *returnSize = 0;
            return NULL;        
        }
        
        // calc the i line
        for (j = 0; j<=(i+1)/2; j++)
        {
            if (j==0 || j==i)       // notice: without j==i, when i=1, will crash
            {
                result[i][j] = 1;
                result[i][i-j] = 1;
            }
            else
            {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
                result[i][i-j] = result[i][j];
            }
        }
    }
    return result;
}

