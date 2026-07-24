class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> postfix  ;
        vector<int> prefix   ;

        long long tmp = 1;
        for(int num : nums){
            tmp *= num;
            prefix.push_back(tmp);
        }
        tmp = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            tmp *= nums[i];
            postfix.push_back(tmp);
        }
        reverse(postfix.begin(), postfix.end());
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if( i == 0){
                ans.push_back(postfix[i + 1]);
            }
            else if(i == nums.size() - 1){
                ans.push_back(prefix[i - 1]);
            }
            else{
                int tmp_ans = prefix[i - 1] * postfix[i + 1];
                ans.push_back(tmp_ans);
            }
        }
        return ans;
    }
};
