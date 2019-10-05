/* using two points, passed: 8ms */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int * res = NULL;
    int tmpSum = 0;
    
    *returnSize = 0;
    res = (int*)malloc(sizeof(int)*2);
    if(NULL == res)
    {
        return NULL;
    }
    res[0] = 0;
    res[1] = numbersSize -1;
    
    while(res[0] < res[1])
    {
        tmpSum = numbers[res[0]]+numbers[res[1]];
        if (tmpSum < target)
        {
            res[0]++;       // move left point
        }
        else if(tmpSum > target)
        {
            res[1]--;       //move right point
        }
        else
        {
            res[0]++;
            res[1]++;
            *returnSize = 2;
            return res;
        }
    }
    return NULL;
}



//-------------------------------------------------------------------------------------------
/* using normal method: passed 12ms */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int diff = 0;
    int i = 0;
    int left = 0, right = 0, mid = 0;
    int *res = NULL;
    
    for(; i<numbersSize; i++)
    {
        diff = target - numbers[i];
        if (diff < numbers[i] || diff > numbers[numbersSize-1])
            continue;
        left = i+1;
        right = numbersSize;
        while(left <= right)
        {
            mid = (left+right)/2;
            if (diff > numbers[mid])
            {
                left = mid+1;
            }
            else if(diff < numbers[mid])
            {
                right = mid-1;
            }
            else
            {
                res = (int*)malloc(sizeof(int)*2);
                if (NULL == res)
                {
                    *returnSize = 0;
                    return NULL;
                }
                res[0] = i+1;
                res[1] = mid+1;
                *returnSize = 2;
                return res;
            }
        }
    }
    
    *returnSize = 0;
    return NULL;
}

