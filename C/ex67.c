
/* normal method, passed 4ms */
char * addBinary(char * a, char * b){
    int lenA = 0, lenB = 0, lenC = 0;
    int i = 0, j = 0, k = 0;
    int tmp = 0, addFlag = 0;
    char *res = NULL,  *newRes = NULL;
    
    lenA = strlen(a);
    lenB = strlen(b);
    lenC = lenA>lenB?lenA+1:lenB+1;
    
    res = (char*)malloc(lenC);
    if (NULL == res)
    {
        return NULL;
    }
    res[lenC-1] = '\0';
    k = lenC-2;
    
    for(i=lenA-1, j=lenB-1; k>=0; i--,j--, k--)
    {
        if (j < 0)
        {
            tmp = a[i] - '0' + addFlag;;
        }
        else if (i < 0)
        {
            tmp = b[j] - '0' + addFlag;
        }
        else
        {
            tmp = a[i] + b[j] - 2*'0' + addFlag;
        }

        if (tmp > 1)
        {
            addFlag = 1;
        }
        else
        {
            addFlag = 0;
        }
        res[k] = tmp%2 + '0';
    }
    /* if need to add 1 char */
    if (addFlag > 0)
    {
        newRes = (char*)malloc(lenC+1);
        if(NULL==newRes)
        {
            free(res);
            return NULL;
        }
        newRes[0] = '1';
        for(k=0; k<lenC; k++)
        {
            newRes[k+1] = res[k];
        }
        
        free(res);
        return newRes;
    }
    else
        return res;
}

