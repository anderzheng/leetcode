

bool isPalindrome(int x){
    long sum = 0;
    int tmp = x;
    if (x < 0)
        return false;
    
    while(x)
    {
        sum = sum*10 + x%10;
        x /= 10;
    }
    
    if (sum == tmp)
        return true;
    else
        return false;

}

