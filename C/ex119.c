
/* using formula of Pascal's triangle, passwd : 0ms */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int * dp = NULL;
    int i=0, j=0;
    long tmp = 0;
    
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

    dp[0] = 1;
    dp[rowIndex] = 1;
    for(i=1;i<=(rowIndex+1)/2; i++)
    {
        /* dp[i] = C(i, k) */
        tmp = (long)dp[i-1] * (rowIndex - i +1)/i;  /* notice: when rowIndex=30, int will over flow */
        dp[i] = tmp;
        dp[rowIndex - i] = tmp;
    }
    
    return dp;
}

//-----------------------------------------------------------------------------------------------------------
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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/* using dynamic programing, a normal way with two temp variable */
/* passed: 4ms */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int * dp = NULL;
    int i=0, j=0;
    int prev = 0, current = 0;
    
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
        dp[0] = 1;
        dp[i] = 1;
        prev = 1;
        for(j=1; j<=i/2; j++)
        {
            current = dp[j];        // notice: using temp var to save the dp[j];
            dp[j] = prev+dp[j];
            dp[i-j] = dp[j];
            prev = current;
        }
    }
    
    return dp;
}

