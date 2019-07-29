

int reverse(int x){
    long sumVal = 0;
    
    while(x != 0)
    {
        sumVal = sumVal*10 + (x%10);
        x /= 10;
    }
    
    if (sumVal > 2147483647 || (sumVal < -2147483648))
        return 0;
    
    return (int)sumVal;

}

