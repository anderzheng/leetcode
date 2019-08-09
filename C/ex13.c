

int romanToInt(char * s){
    int sum = 0;
    int cVal['X'+1] = {0};
    cVal['I'] = 1;
    cVal['V'] = 5;
    cVal['X'] = 10;
    cVal['L'] = 50;
    cVal['C'] = 100;
    cVal['D'] = 500;
    cVal['M'] = 1000;
    while(*s)
    {
        if ((*s) > 'X' || (*s)<'C' || cVal[*s] == 0)
            return 0;
        
        if ((*s == 'I' && (*(s+1) == 'V' || *(s+1) == 'X'))  ||
            (*s == 'X' && (*(s+1) == 'L' || *(s+1) == 'C'))  ||
            (*s == 'C' && (*(s+1) == 'D' || *(s+1) == 'M'))
            )
        {
            sum += (cVal[*(s+1)] - cVal[*s]);
            s+=2;
        }
        else
        {
            sum += cVal[*s];
            s++;
        }
    }
    return sum;  

}

