/* passed: 0ms */

int titleToNumber(char * s){
    int ch  = 0;
    int sum = 0;
    
    while(*s)       /* notic: *s 8/
    {
        ch = *s - 'A'+1;
        sum = sum*26+ch;
        s++;
    }
    
    return sum;
}

