

/* using dp method, passed: 4ms */

int rob(int* nums, int numsSize){
    int *dp = NULL;
    int i = 0, maxSum = 0;
    
    if (NULL == nums || numsSize < 1)
        return 0;
    
    if (numsSize == 1)
        return nums[0];
    
    dp = (int*)malloc(sizeof(int)*numsSize);
    if (NULL == dp)
    {
        return 0;
    }
    
    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1]? nums[0]:nums[1];
    
    for(i=2;i<numsSize;i++)
    {
        maxSum = dp[i-2] + nums[i];
        if (maxSum > dp[i-1])
        {
            dp[i] = maxSum;
        }
        else
        {
            dp[i] = dp[i-1];
        } 
    }
    
    maxSum = dp[numsSize -1];
    free(dp);
    
    return maxSum;
}

