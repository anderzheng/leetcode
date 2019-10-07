/* passed 0 ms */
/* the number of trailing zero equals the number of 5 in the n!,
   and like the 25 = 5*5, means two of 5 */

int trailingZeroes(int n){
    int res = 0;
    
    while(n != 0)
    {
        res += n/5;
        n = n/5;
    }
    
    return res;
}
