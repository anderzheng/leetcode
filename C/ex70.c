
/* using dynamic programing method, 4ms */

int climbStairs(int n){
    int *dp = NULL;
    int i = 0, res = 0;
    
    if (n == 1)
    {
        return 1;
    }
    
    dp = (int*)malloc(sizeof(int)*n);
    if (NULL == dp)
    {
        return 0;
    }
    dp[0] = 1;      /* 0 means the 1 step stair */
    dp[1] = 2;      /* notice: if n == 1, this will be error */
    
    for(i = 2; i<n; i++)
    {
        dp[i] = dp[i-2] + dp[i-1];      /* 斐波那契 */
    }
    
    res = dp[n-1];
    free(dp);
    return res;
}

