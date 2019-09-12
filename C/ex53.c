/*
Using dynamic programing method.
*/

int maxSubArray(int* nums, int numsSize){
    int i=0, j=0;
    int *dp = NULL;
    int maxVal = 0, tmpSum = 0;
    
    if (nums == NULL || numsSize < 1)
    {
        return 0;
    }
    
    dp = (int*)malloc(sizeof(int)*numsSize);
    if (NULL == dp)
    {
        return 0;
    }
    
    dp[0] = nums[0];
    maxVal = dp[0];
    for(i=1; i<numsSize; i++)
    {
        // dp[i-1] is the largest sum in [0~i-1], then,
        // dp[i] = max(dp[i-1]+nums[i], nums[i])
        tmpSum = dp[i-1]+nums[i];
        dp[i] = tmpSum >nums[i]?tmpSum:nums[i];

        // find the max in dp[0~i]
        if (maxVal < dp[i])
        {
            maxVal = dp[i];
        }
    }
    free(dp);
    
    return maxVal;
}

