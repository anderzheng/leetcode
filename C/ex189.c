
/* directly move: passed 16ms */
void rotate(int* nums, int numsSize, int k){
    int tmp = 0, cnt = 0;
    int flag = 0, start = 0, end = 0;
    int prev = 0;
    k = k%numsSize;
    
    for(;cnt<numsSize;)
    {
        start = flag;
        prev = nums[start];
        do
        {
            end = (start+k)%numsSize;
            tmp = nums[end];
            nums[end] = prev;
            prev = tmp;
            start = end;
            cnt++;
        }while(end != flag);
        flag ++;    // move to next
    }
}

#if 0
/* normal method, time out */
void rotate(int* nums, int numsSize, int k){
    int tmp = 0, i = 0, j = 0;
    
    k = k%numsSize;
    if (NULL == nums || numsSize<1 || k<1)
    {
        return;
    }
    for(;j<k; j++)
    {
        // rotate 1 times
        tmp = nums[numsSize-1];
        for(i=numsSize-1; i>0; i--)
        {
            nums[i] = nums[i-1];
        }
        nums[0] = tmp;
    }
        return;
}
//#if 0
/* using extra space: passed 20ms */
void rotate(int* nums, int numsSize, int k){
    int tmp = 0, i = 0, j = 0;
    int *buff = NULL;
    
    k = k%numsSize;     // if times of numsSize, needn't rotate
    if (NULL == nums || numsSize<1 || k<1)
    {
        return;
    }
    
    buff = (int*)malloc(sizeof(int)*k);
    if (NULL == buff)
    {
        return;
    }
    for(;j<k; j++)
    {
        // backup
        buff[j] = nums[numsSize-k+j];
    }
    // rotate
    for(i=numsSize-1; i>=k; i--)
    {
        nums[i] = nums[i-k];
    }
    // restore
    for(j=0;j<k; j++)
    {
        nums[j] = buff[j];
    }
    return;
}
#endif

