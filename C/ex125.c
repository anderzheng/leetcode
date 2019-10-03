/* passed :4ms */

int UPPER = 'A' - 'a';
int LOWER = 'a' - 'A';

char convert2Lower(char ch)
{
    if ((ch >= '0' && ch <= '9') ||
       (ch >= 'a' && ch <= 'z'))
        return ch;
    else if (ch >= 'A' && ch <= 'Z')
        return ch+LOWER;
    else
        return 0;
}

char convert2Upper(char ch)
{
    if ((ch >= '0' && ch <= '9') ||
       (ch >= 'A' && ch <= 'Z'))
        return ch;
    else if (ch >= 'a' && ch <= 'z')
        return ch+UPPER;
    else
        return 0;
}

bool isPalindrome(char * s){
    int len = 0, i = 0, j=0;
    char ch1 = 0, ch2 = 0;
    
    if (NULL == s)
        return false;
    
    len = strlen(s);
    if (len <= 1)
        return true;
    
    j = len-1;
    while(i<j)
    {
        ch1 = convert2Lower(s[i]);
        while(ch1 == 0 && i < j)        // this while can be omitted, using the outside while.
        {                               // but in order to reduce the times of calling convert2Lower()
            ch1 = convert2Lower(s[++i]);
        }

        ch2 = convert2Lower(s[j]);
        while(ch2 == 0 && i < j)
        {
            ch2 = convert2Lower(s[--j]);
        }
              
        if (ch1 != ch2)
            return false;
        i++;
        j--;
    }
    
    return true;
}

