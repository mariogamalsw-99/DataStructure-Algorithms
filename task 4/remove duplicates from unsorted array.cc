vector<int> findDuplicates(vector<int>& nums) {

        unordered_set<int> freq_set{};
        vector<int> ret{}; 
        for(auto it=nums.begin();it<nums.end();)
        {
            if(freq_set.find(*it)==freq_set.end())
            {
                //first appearence >> add to set
                freq_set.insert(*it);
                it++;
            }
            else
            {
                //found before >> remove from original or add to new vector with duplicates
                ret.push_back(*it);
                nums.erase(it);
            }
        }
        return ret;
    }