class Solution {
    private:
    void Solve(int ind,vector<vector<int>>& result,vector<int>& ds,vector<int>& candidates,int target,int n){
        if(ind==n){
            if(target==0) result.push_back(ds);
            return;
        }
        // Picking an element
        // Checking if sum do not become less than 0
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            Solve(ind,result,ds,candidates,target-candidates[ind],n);
            // Removeing the element for backtracking
            ds.pop_back();
        }
        // Not picking an element
        Solve(ind+1,result,ds,candidates,target,n);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) { 
        // https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=52
        // At every time we are picking an element or not picking an element so we use the method of recursion
        // there is a clause that we can pick up an element as many times we want so do not increase the index in recursion when ever we pick up an element
        // But if we do not pick up an element we increase the index
        // At every time when we pick up an element we reduce the target as target-element
        // Our base condition of recursion becomes when we reach the last index or when our target becomes less than equal to zero then we return
        // if our target becomes 0, then we add that array to our ds
        // Code

        vector<vector<int>> result;
        vector<int> ds;
        int n=candidates.size();
        Solve(0,result,ds,candidates,target,n);
        return result;
    }
};