int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX;
        auto left=nums.begin(),right=nums.begin();
        int sum=0;;
        while(right!= nums.end())
        {
            // add right
            sum+=*right;
            //check if sum greater than or equal target
            if(sum>= target )
            {
                //then take the min length and shrink
                res=min(res,int((right-left)+1));
                while(sum>=target)
                {
                     res=min(res,int((right-left)+1));
                    sum-=*left;
                    left++;
                }
            }
            right++;
        }
        return res==INT_MAX? 0 : res;
    }