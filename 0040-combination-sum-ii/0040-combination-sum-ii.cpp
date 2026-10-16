class Solution {
    private:
    void Solve(int ind,vector<vector<int>>& ans,vector<int>& ds,vector<int>& candidates,int target){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        // Selection of picking
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            Solve(i+1,ans,ds,candidates,target-candidates[i]);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=51
        // Now we will modify our recursion method
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        Solve(0,ans,ds,candidates,target);
        return ans;
    }
};