
/* define a dict with 256 letters */
/* passed 4ms */

bool isIsomorphic(char * s, char * t){
    char dict_s[256] = {'\0'};
    char dict_t[256] = {'\0'};  // notic: need 2 dict
    int idx = 0;
    int i = 0;
    
    while(s[i] && t[i])
    {
        idx = s[i];
        if (dict_s[idx] != '\0')
        {
            if (dict_s[idx] != t[i])
            {
                return false;
            }
        }
        else
        {
            dict_s[idx] = t[i];
        }
        
        idx = t[i];
        if (dict_t[idx] != '\0')
        {
            if (dict_t[idx] != s[i])
            {
                return false;
            }
        }
        else
        {
            dict_t[idx] = s[i];
        }

        i++;
    }
    
    return true;
}
