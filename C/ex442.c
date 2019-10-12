/* normal: passed 124ms */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int *buff = NULL, *res = NULL;
    int cnt = 0, i = 0, j=0;
    
    if(NULL == nums || numsSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    
    buff = (int*)malloc(sizeof(int)*numsSize);
    if (NULL == buff)
    {
        *returnSize = 0;
        return NULL;
    }
    memset(buff, 0, sizeof(int)*numsSize);
    
    for(i=0;i<numsSize;i++)
    {
        buff[nums[i]-1]++;
        if (buff[nums[i]-1] == 2)
            cnt++;
    }
    res = (int*)malloc(sizeof(int)*cnt);
    if (NULL == res)
    {
        free(buff);
        *returnSize = 0;
        return NULL;
    }
    
    for(i=0;i<numsSize;i++)
    {
        if (buff[i] == 2)
            res[j++] = i+1;
    }
    free(buff);
    *returnSize = cnt;
    
    return res;
}
