
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        //get first sum
            int sum =0;
            for(int i=0;i<k;i++)
            {
                sum+=arr[i];
            }
            int avg=sum/k;
            int max=sum;
            //slide window
            for(int i=1;i<=arr.size()-k;i++)
            {
                //silde sum
                sum-=arr[i-1];
                sum+=arr[i+k-1];
                avg=sum/k;
                if(max<avg)
                {
                    max=avg;
                }
            }
            return max;
    }