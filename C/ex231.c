
/* passed 4ms */
bool isPowerOfTwo(int n){
    
    while(n> 0)
    {
        if ((n&1) == 0) // notice: (n&1) is needed
        {
            n >>= 1;
            continue;
        }
        else
        {
            n >>=1;
            if (n == 0)
                return true;
            else
                return false;
        }
    }
    
    return false;
}
