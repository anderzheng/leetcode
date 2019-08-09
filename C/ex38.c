
char buff[30] = {'\0'};

int countInt(int n)
{
    int res = 0;
    if (n == 1)
        return 1;
    res = countInt(n-1);
    while(res >= 0)
    {
        if (tmp == res % 10)
        {
            cnt ++;
        }
        else
        {
            cnt = 1;
            if (tmp !=0 )
            {
                newRes = 
            }
        }
        res /=10;
        tmp = res%10;
    }
}
char * countAndSay(int n){
    char *str = NULL;
    char tmp[3] = {'\0'};
    
    if (n == 1)
        return "1";
    
    str = coutAndSay(n-1);
    while(*str)
    {
        if (str[i] == str[i+1])
        {
            cnt ++;
        }
        else
        {
            snprintf(tmp, "%d%d", cnt, str[i]);
        }
    }
}

