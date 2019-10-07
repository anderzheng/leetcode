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
