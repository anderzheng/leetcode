
/* merget from back, without malloc backup array, passed 4ms */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = 0, j= 0, k= 0;
    
    for(i=m-1,j=n-1,k=m+n-1;i>=0&& j>=0;k--)
    {
        if (nums1[i] < nums2[j])
        {
            nums1[k] = nums2[j];
            j--;
        }
        else
        {
            nums1[k] = nums1[i];
            i--;
        }
    }
    for (;i>=0; i--)             // copy last data from nums1
    {
        nums1[k--] = nums1[i];
    }
    for(;j>=0; j--)             // copy last data from nums2
    {
        nums1[k--] = nums2[j];
    }
    
    return;
}


/* use a tmp array, passed 8ms */

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int *tmp = NULL;
    int i = 0, j= 0, k= 0;
    
    tmp = (int*) malloc(sizeof(int)*m);
    if (NULL == tmp)
    {
        return ;
    }
    
    for(i=0;i<m;i++)
    {
        tmp[i] = nums1[i];      // backup
    }
    for(i=0,j=0,k=0;i<m && j<n;k++)
    {
        if (tmp[i] > nums2[j])
        {
            nums1[k] = nums2[j];
            j++;
        }
        else
        {
            nums1[k] = tmp[i];
            i++;
        }
    }
    for (;i<m; i++)             // copy last data from nums1
    {
        nums1[k++] = tmp[i];
    }
    for(;j<n; j++)             // copy last data from nums2
    {
        nums1[k++] = nums2[j];
    }
    
    free(tmp);
    return;
}

