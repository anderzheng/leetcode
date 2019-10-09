/* using  Sieve of Eratosthenes method */
/* passed 52ms */

int countPrimes(int n)
{
    int *buff = NULL;
    int i = 0, j = 0, cnt = 0;
    
    if (n <= 2)
        return 0;
    
    buff = (int*)malloc(sizeof(int)*n);
    if (NULL == buff)
        return 0;
    for(;i<n;i++)
        buff[i] = 1;
    
    for(i=2;i*i<=n; i++)
    {
        for(j=i*i;j<n;j+=i)  // notice
        {
            buff[j] = 0;  // j = i*times;
        }
    }
    for(i=2; i<n; i++)      // skip 0 and 1
        cnt += buff[i];
    
    free(buff);
    return cnt;
}

#if 0
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

#endif
