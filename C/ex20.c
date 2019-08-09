

bool isValid(char * s){
    char *cStack = NULL;
    int ptr = 0;
    char ch = 0;
    int iRight=0, len = 0;
    
    if (NULL == s)
        return false;
    
    len = strlen(s);
    cStack = malloc(len+1);
    if (NULL == cStack)
        return false;

    ch = s[iRight];
    while(ch)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            cStack[ptr++] = ch;
            iRight++;
        }
        else if (ch == ')')
        {
            if (ptr > 0 && 1 == abs(cStack[ptr-1] -ch))   // match
            {
                cStack[--ptr] = '\0';
                iRight ++;
            }
            else    // not match
            {
                break;
            }
        }        
        else if (ch == ']')
        {
            if (ptr > 0 && cStack[ptr-1] == '[')   // match
            {
                cStack[--ptr] = '\0';
                iRight ++;
            }
            else    // not match
            {
                break;
            }
        }
        else if (ch == '}')
        {
            if (ptr > 0 && cStack[ptr-1] == '{')   // match
            {
                cStack[--ptr] = '\0';
                iRight ++;
            }
            else    // not match
            {
                break;
            }
        }
        else        // unknown char
            break;

        ch = s[iRight];
    }
    
    free(cStack);
    
    return (ptr==0&&iRight==len)?true:false;
}

