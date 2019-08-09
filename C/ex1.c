

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i=0, j=0;
    int *resNums =NULL;
    int tmpVal = 0;
    int maxVal = 0, minVal=0;
    int hashSize = 0;
    int *hashTbl = NULL;
    *returnSize=0;
    
    if (nums == NULL)
        return NULL;
    
    maxVal = minVal = nums[0];
    
    for(i=1; i<numsSize; i++)
    {
        if (nums[i] > maxVal)
            maxVal = nums[i];
        if (nums[i] < minVal)
            minVal = nums[i];
    }
    
    hashSize = maxVal - minVal + 1;
    hashTbl = (int*)malloc(hashSize* sizeof(int));
    if (NULL == hashTbl)
    {
        return NULL;
    }
    memset((char*)hashTbl, 0xFF, hashSize*sizeof(int));
    
    for(i=0;i<numsSize;i++)
    {
        tmpVal = target - nums[i];
        if (tmpVal >= minVal && tmpVal <= maxVal)
        {
            if (hashTbl[tmpVal] < 0)
            {
                resNums = malloc(sizeof(int) *2);
                if (NULL == resNums)
                {
                    return NULL;
                }
                resNums[0] = hashTbl[tmpVal];
                resNums[1] = i;
                break;
            }
        }
        hashTbl[nums[i]] = i;
    }
    return resNums;
}
