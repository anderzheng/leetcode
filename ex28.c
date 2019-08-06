

int strStr(char * haystack, char * needle){
    int pos = 0, i= 0, j=0;
    if (NULL == haystack || NULL == needle)
        return -1;
    if (*needle == '\0')
        return 0;
    while(haystack[i] && needle[j])
    {
        if (haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else
        {
            pos ++;
            i = pos;
            j = 0;
        }
    }
    if (needle[j] == '\0')
        return pos;    

    return -1;
}

