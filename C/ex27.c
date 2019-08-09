

int removeElement(int* nums, int numsSize, int val){
    int pos = 0, i=0;
    
    for(i=0; i<numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[pos++] = nums[i];
        }
    }
    
    return pos;
}

