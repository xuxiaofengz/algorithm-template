//力扣：滑动窗口的最值
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            while(!que.empty()&&nums[que.front()]<=nums[i]){
                que.pop_front();
            }
            que.push_front(i);
            if(que.back()<=i-k){
                que.pop_back();
            }
            if(i>=k-1){//窗口足够大
                res.push_back(nums[que.back()]);
            }
        }
        return res;
    }
