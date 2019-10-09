/* normal method, passed 692 ms */

bool isPrime(int n)
{
    int i = 0;
    if (n == 0 || n==1)
        return false;
    
    for(i=2;i*i<=n; i++)       // optimize the loop, or else will timeout
    {
        if (n%i == 0)
            return false;
    }
    
    return true;
}

int countPrimes(int n){
    int i = 0, cnt = 0;
    
    for(i=1;i<n; i++)
    {
        if (isPrime(i))
            cnt++;
    }
    
    return cnt;
}
