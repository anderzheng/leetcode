
/* using slow-fast point to detect circle */
/* passed 4ms */

int calcSum(int n)
{
    int sum = 0;
    
    while(n > 0)
    {
        sum += (n%10)*(n%10);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    int fast = 0, slow = 0;
    
    slow = n;
    fast = calcSum(n);
    while(fast != slow)
    {
        slow = calcSum(slow);
        fast = calcSum(fast);
        fast = calcSum(fast);   // calc twice
    }
    if (fast == 1)
        return true;
    else
        return false;
}

#if 0
/* using iterative method, time out when n == 2 */
bool isHappy(int n)
{
    int tmp = 0, sum = 0;
    int stack[8] = {0};
    int top = 0;
    
    stack[0] = n;
    top = 1;
    
    while(top > 0)
    {
        tmp = stack[--top];
        sum = 0;
        while(tmp > 0)
        {
            sum += (tmp%10)*(tmp%10);
            tmp /= 10;
        }
        if (sum == 1)
            return true;
        else if(sum == n)
            return false;
        else
            stack[top++] = sum;
    }
    
    return false;
}

/* using recursive method, stack overflow when n == 2 */

bool isHappySub(int n, int org)
{
    int sum = 0;
    
    while(n > 0)
    {
        sum += (n%10)*(n%10);
        n /= 10;
    }
    
    if (sum == 1)
        return true;
    else if(sum == org)
        return false;
    else
        return isHappySub(sum, org);
}

bool isHappy(int n){
    if (n == 0)
        return false;
    return isHappySub(n, n);
}

#endif
