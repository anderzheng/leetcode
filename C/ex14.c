

char * longestCommonPrefix(char ** strs, int strsSize){
    int pos = 0, i = 0, maxLen = 0;
    char *res = NULL;
    
    if (strs == NULL || strsSize == 0)
    {
        res = malloc(1);
        res[0] = '\0';
        return res;
    }
    maxLen = strlen(strs[0]);
    for(i=1; i< strsSize; i++)
    {
        pos = 0;
        while (pos < maxLen && strs[0][pos]!= '\0' && strs[i][pos]!='\0' && strs[i][pos] == strs[0][pos])
            pos++;
        maxLen = pos;
    }
    res = malloc(maxLen+1);
    if (NULL == res)
        return NULL;
    if (maxLen > 0)
        strncpy(res, strs[0], maxLen);
    res[maxLen] = '\0';
    return res;
}

