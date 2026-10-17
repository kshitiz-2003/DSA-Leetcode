class Solution {
    private:
    void Solve(int ind,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans){
        ans.push_back(ds);
        //Loop from ind to n-1
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            Solve(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=55
        // Similar to comination sum II with slight difference
        // Code
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        Solve(0,nums,ds,ans);
        return ans;
    }
};