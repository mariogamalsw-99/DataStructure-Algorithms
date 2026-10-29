#include <stdio.h>

//count number of pairs that have the sum of K 
unsigned int ParitWithSumOfK(int*arr,unsigned int size,unsigned int k)
{
    //arr is ordered
    unsigned int left=0,right = size-1;
    unsigned  int count=0;
    while(left<=right)
    {
        int sum=arr[left]+arr[right];
        if(sum==k)
        {
            count++;
            left++;
        }
        else if(sum<k)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return count;
}


int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    unsigned int res=ParitWithSumOfK(arr,sizeof(arr)/sizeof(int),11);
    printf("%d",res);
    return 0;
}