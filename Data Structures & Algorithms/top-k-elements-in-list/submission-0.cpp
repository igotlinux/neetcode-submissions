class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int n: nums){
            freq[n]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for(auto n: freq){
            bucket[n.second].push_back(n.first);
        }

        vector<int> ans;
        for(int i = bucket.size() - 1; i >= 0 && ans.size() <= k; i--)
        {
            for(auto num : bucket[i]){
                ans.push_back(num);
                if(ans.size() == k){
                    return ans;
                }
            }
        }
    }
};
