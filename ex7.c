

int reverse(int x){
    unsigned int absX = 0;
    long sumVal = 0;
    
    if (x < 0)
        absX = -x;
    else
        absX = x;
    while(absX > 0)
    {
        sumVal = sumVal*10 + (absX%10);
        absX /= 10;
    }
    
    if (sumVal > 0x7FFFFFFF || (x <0 && sumVal > (unsigned int)0x80000000))
        return 0;
    
    return x<0?-sumVal:sumVal;

}

