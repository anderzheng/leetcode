/* new method: using n&n-1 to delete the last 1 in right */

int hammingWeight(uint32_t n) {
    int res = 0;
    while(n!=0)
    {
        res++;
        n = n&(n-1);
    }
    return res;
}
//---------------------------------------------------------------------
/* passed: 0ms */

int hammingWeight(uint32_t n) {
    int res = 0;
    int i = 0;
    
    for(; i<32 && n>0; i++)
    {
        if(n&1 > 0)
            res++;
        n >>= 1;
    }
    
    return res;
}
