/* passed: 0ms */

char * convertToTitle(int n){
    int tmp = 0, cnt = 0, i = 0;
    char buff[1024] = {'\0'};
    char *res = NULL;
    
    while(n>0)
    {
        tmp = n%26;
        n = n/26;
        
        if (tmp == 0)
        {
            tmp = 26;
            n--;        // notice
        }
        buff[cnt++] = tmp+'A'-1;
    }
    if (cnt > 0)
    {
        res = (char*)malloc(cnt+1);
        if(NULL == res)
            return NULL;
        for(i=0; i<cnt; i++)
        {
            res[i] = buff[cnt-i-1];
        }
        res[i] = '\0';
    }
    return res;
}

