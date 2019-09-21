/* nomoral method: 20ms */
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

/* binary divide method: 4ms */
/* find the digits n, that  (n+1)*(n+1) > x && n*n < x */

int mySqrt(int x){
    int right = 0, mid = 0, left = x;         /* notice: must use unsigned int 64 */
    unsigned long long tmpVal = 0;
    
    while(left - right > 1)
    {
        mid = (left+right)/2;
        tmpVal = (unsigned long long)mid*mid;           /* notice: tmpVal maybe greater than unsigned int
                                        so, need to use int64 */
        
        if (tmpVal < x)
        {
            right = mid;
        }
        else if (tmpVal > x)
        {
            left = mid;
        }
        else
        {
            return mid;
        }
    }
    
    if ((unsigned long long)left*left == x)
    {
        return left;
    }
    else
    {
        return right;
    }
    
    return right;
}

