

char * longestCommonPrefix(char ** strs, int strsSize){
    int pos = 0, i = 0, minLen = 0;
    char *res = NULL;
    
    if (strs == NULL || strsSize == 0)
    {
        res = malloc(1);
        res[0] = '\0';
        return res;
    }
    
    minLen = strlen(strs[0]);
    for (i=0; i< strsSize; i++)
    {
        if (strs[i] == NULL)
        {
            res = malloc(1);
            res[0] = '\0';
            return res;
        }
        if (minLen > strlen(strs[i]))
        {
            minLen = strlen(strs[i]);
        }
    }
    
    while(strs[0][pos] != '\0')
    {
        if (pos >= minLen)
        {
            break;
        }
        for(i=0; i< strsSize; i++)
        {
            if (strs[i][pos] != strs[0][pos])
                break;
        }
        if (i < strsSize)
        {
            break;
        }
        pos++;
    }
    res = malloc(pos+1);
    if (NULL == res)
        return NULL;
    if (pos > 0)
        strncpy(res, strs[0], pos);
    res[pos] = '\0';
    return res;
}

