/* using normal method,  passed: 8ms */

int maxProfit(int* prices, int pricesSize){
    int i = 0, min = 0, maxDiff = 0, sum = 0;
    
    if (NULL == prices ||
       0 == pricesSize)
        return 0;
    
    min = prices[0];
    for(i=1; i<pricesSize; i++)
    {
        if(maxDiff < prices[i]-min)
        {
            maxDiff = prices[i] - min;
        }
        else
        {
            min = prices[i];
            sum += maxDiff;
            maxDiff = 0;        // notice : after selled, next profit is 0
        }
    }
    
    sum += maxDiff;     //notice : need to add the last profit 
    
    return sum;
}
