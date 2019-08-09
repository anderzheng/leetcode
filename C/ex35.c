

int searchInsert(int* nums, int numsSize, int target){
    int top = 0, bottom = numsSize -1, pos = 0;
    
    if (numsSize < 1)
    {
        return 0;
    }
    while(top <= bottom)
    {
        pos = (top + bottom)/2;
        if (nums[pos] < target)
        {
            top = pos + 1;
        }
        else if (nums[pos] > target)
        {
            bottom = pos - 1;
        }
        else
        {
            return pos;
        }
    }
    if (nums[pos] < target)
        return pos+1;
    else
        return pos;
}

