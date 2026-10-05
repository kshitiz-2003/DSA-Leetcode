class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Bit manipulation method
        // Watch from youtube
        // https://www.youtube.com/watch?v=b7AYbpM5YrE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=70

        // code
        vector<vector<int>> ans;
        int n=nums.size();
        // 1<<n =2^n
        // There are 2^n possible subsets
        for(int i=0;i<=(1<<n)-1;i++){
            vector<int> sub;
            for(int j=0;j<n;j++){
                if((i & (1<<j))!=0){
                     // Check the jth bit of i
                    sub.push_back(nums[j]);
                }
            }
            ans.push_back(sub);
        }
        return ans;
    }
};