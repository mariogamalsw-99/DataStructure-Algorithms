
int subarraySum(vector<int> &nums, int k)
{
    int res = 0;
    int l = 0, r = 0;
    int sum = 0;
    while (r < nums.size())
    {
        sum += nums[r];
        if (sum == k)
        {
            res++;
        }
        while (sum > k)
        {
            sum -= nums[l];
            l++;
            if (sum == k && l < nums.size())
            {
                res++;
            }
        }
        r++;
    }
    return res;
}
 