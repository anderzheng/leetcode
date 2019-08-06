

int searchInsert(int* nums, int numsSize, int target){
    int prev = 0, next = numsSize -1;
    
    if (numsSize < 1)
    {
        return 0;
    }
    while(prev <= next)
    {
        if (nums[prev] >= target)
        {
            return prev;
        }
        if (nums[next] < target)
        {
            return next+1;
        }
        else if (nums[next] == target)
        {
            return next;
        }
        prev++;
        next--;
    }
    
    return prev;
}

