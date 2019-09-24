/* passed: 104ms */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
    int i = 0, j = 0;
    int tmp = 0, addFlag = 0;
    int *res = NULL;
    int buff[8] = {0};

    if (K == 0)
    {
        res = (int*)malloc(ASize*sizeof(int));
        if (NULL == res)
            return NULL;
        for(i=0; i< ASize; i++)
        {
            res[i] = A[i];
        }
        *returnSize = ASize;    /* notice: don't forget */
        return res;
    }

    i = ASize - 1;
    while(i>=0)
    {
        A[i] = A[i] + addFlag + K%10;
        addFlag = A[i]/10;
        A[i] %= 10;
        
        K /= 10;
        i--;
    }
    while (K > 0 || addFlag > 0)      /* K is longer than A */
    {
        buff[j] = addFlag + K%10;
        addFlag = buff[j] / 10;
        buff[j] %= 10;
        
        K /= 10;
        j++;
    }
    
    res = (int*) malloc(sizeof(int)*(ASize + j));
    if (NULL == res)
    {
        return NULL;
    }
    *returnSize = ASize+j;
    
    i = 0;
    /* set the result */
    for (; i<j; i++)
    {
        res[i] = buff[j-i-1];
    }
    for (;i<*returnSize; i++)
    {
        res[i] = A[i-j];
    }
    
    return res;
}

