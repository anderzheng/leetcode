
/* using dp method: passwd 12ms */

int maxProfit(int* prices, int pricesSize){
    int *dp = NULL;
    int i=0, min = 0, maxDiff = 0;
    
    if (prices == NULL ||
       pricesSize == 0)
    {
        return 0;
    }
    
    dp = (int*)malloc(sizeof(int)*pricesSize);
    if (NULL == dp)
    {
        return 0;
    }
    
    min = prices[0];
    dp[0] = 0;
    for(i=1; i<pricesSize; i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
            dp[i] = 0;      // current maximum profit is 0
        }
        else
        {
            dp[i] = prices[i] - min;
            if (maxDiff < dp[i])
            {
                maxDiff = dp[i];
            }
        }
        
    }
    
    free(dp);
    
    return maxDiff;
}

