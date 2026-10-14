class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // https://www.youtube.com/watch?v=MpUMQBvAa8k
        // code 1
        for(int i=0;i<nums.size();i++){
            int square=nums[i]*nums[i];
            nums[i]=square;
        }
        sort(nums.begin(),nums.end());
        long long small=accumulate(nums.begin(),nums.begin()+(nums.size()/2),0LL);
        long long large=accumulate(nums.begin()+(nums.size()/2),nums.end(),0LL);
        return large-small;

    }
};