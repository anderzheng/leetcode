/* passed: 12ms */
/* using xor operation */
int singleNumber(int* nums, int numsSize){
    int i = 0, tmp  = 0;
    
    if (NULL == nums)
        return 0;
    
    tmp = nums[0];
    for(i = 1; i< numsSize; i++)
    {
        tmp ^= nums[i];
    }
    return tmp;
}

