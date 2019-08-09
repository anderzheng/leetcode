

int removeDuplicates(int* nums, int numsSize){
    int pos = 0, i = 0;
    if (numsSize <= 1)
    {
        return numsSize;
    }
    for (i=1; i<numsSize; i++)
    {
        if(nums[pos] != nums[i])
        {
            pos++;
            nums[pos] = nums[i];
        }
    }
    
    return pos+1;
}

