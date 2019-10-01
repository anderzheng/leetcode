
/* using dynamic programing, passed: 4ms */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int * dp = NULL;
    int i=0, j=0;
    
    if (rowIndex < 0)
    {
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = rowIndex+1;
    dp = (int*)malloc(*returnSize*sizeof(int));
    if (NULL == dp)
    {
        *returnSize = 0;
        return NULL;
    }
    for(i=0;i<rowIndex+1; i++)
    {
        dp[i] = 0;
    }
    for(i=0;i<rowIndex+1; i++)
    {
        for(j=i/2; j>=0; j--)      /* notice: from mid to left, in order to prevent dp[j-1] */
        {
            if (j==0)
            {
                dp[j] = 1;
                dp[i] = 1;
            }
            else
            {
                dp[j] = dp[j-1]+dp[j];
                dp[i-j] = dp[j];
            }
        }
    }
    
    return dp;
}

