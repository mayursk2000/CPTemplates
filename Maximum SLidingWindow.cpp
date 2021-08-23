    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i,n=nums.size();
        deque<pair<int,int>>d;
        vector<int>v;
        for(i=0;i<n;i++){
            if(i<k){
                while(!d.empty()&&d.back().first<nums[i])
                d.pop_back();
                d.push_back({nums[i],i});
                if(i==k-1)
                v.push_back(d.front().first);
            }
            else{
                if(!d.empty()&&d.front().second<i-k+1)
                d.pop_front();
                while(!d.empty()&&d.back().first<nums[i])
                d.pop_back();
                d.push_back({nums[i],i});
                v.push_back(d.front().first);
            }
        }
        return v;
    }
};
