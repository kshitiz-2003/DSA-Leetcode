class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
       for(int i=0;i<k;i++){
            sum+=nums[i];
       }
       int MaxSum=sum;
       for(int i=k;i<nums.size();i++){
            sum=sum+nums[i]-nums[i-k];
            MaxSum=max(MaxSum,sum);
       }
        return (double)MaxSum/k;
    }
};