/* nomoral method */
/* find the digits n, that  (n+1)*(n+1) > x && n*n < x */

int mySqrt(int x){
    unsigned int i = 0;         /* notice: must use unsigned int */
    unsigned int tmpVal = 0;
    
    for(i=0; i<=x; i++)     /* notice: i<=x, when x=2, i need to try x */
    {
        tmpVal = i*i;
        if (tmpVal == x)
        {
            break;
        }
        else if(tmpVal > x)
        {
            i--;
            break;
        }
    }
    return i;
}

