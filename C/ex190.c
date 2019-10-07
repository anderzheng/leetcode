/* normal method, passed: 4ms */

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0, flag = 0;
    int i = 0;
    
    for(;i<32; i++)
    {
        flag = ((uint32_t)1<<i);
        if (i < 16)
            res |= ((n&flag) << (31-2*i));
        else
            res |= ((n&flag) >> (2*i-31));
    }
    
    return res;
}
