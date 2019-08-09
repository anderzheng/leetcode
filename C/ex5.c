int checkSubStr(char *s, int len)
{
    char *pHead = s, *pTail = s+len;
    
    while(pHead < pTail)
    {
        if (*pHead != *pTail)
            return 1;
        pHead ++;
        pTail --;
    }
    return 0;
}

char * longestPalindrome(char * s){
    char *pHead = s, *pTail=NULL, *pTmp= NULL;
    int strSize = 0;
    int *resLen=NULL;
    int maxLen = 0,maxIdx = 0;
    char *result = NULL;
    
    if (NULL == s)
        return NULL;
    
    strSize = strlen(s);
    if (strSize > 1000)
        return NULL;
    
    resLen = (int*)malloc(sizeof(int)*strSize);
    if (NULL == resLen)
        return NULL;
    memset((char*)resLen, 0, sizeof(int)*strSize);
    
    while(*pHead != '\0')
    {
        pTail = s+strSize-1;
        while (pTail!=pHead)
        {
            if (0 == checkSubStr(pHead, pTail - pHead))
            {
                resLen[pHead-s] = (pTail - pHead) + 1;
                if (maxLen < resLen[pHead-s])
                {
                    maxLen = resLen[pHead-s];
                    maxIdx = pHead -s;
                }
                break;
            }
            else
            {
                pTail --;
            }
        }
        pHead ++;
    }
    result = (char*)malloc(maxLen);
    if (NULL == result)
        return NULL;
    return strncpy(result, s+maxIdx, maxLen);
}

