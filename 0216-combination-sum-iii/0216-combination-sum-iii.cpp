class Solution {
    private:
    void Solve(int ind,vector<vector<int>>& ans,vector<int>& ds,int k,int n){
        if(k==0 && n==0){
            ans.push_back(ds);
            return;
        }
        if(k==0 || n<=0){
            return;
        }
        for(int i=ind;i<=9;i++){
            ds.push_back(i);
            Solve(i+1,ans,ds,k-1,n-i);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // Similar to combination Sum2
        // We apply the loop recursive method of combination sum2
        // Step 1: Base case
        //  If k == 0 and n == 0, we have selected exactly the required number of elements and achieved the required sum. Store ds in ans.
        // Step 2: Prune invalid cases
        // If k == 0 but n != 0, or n == 0 but k != 0, stop that recursive path. We cannot form a valid combination.
        // Step 3: Try each number
        // Loop from start to 9. For every number i, select it, recursively search for the remaining k - 1 numbers and n - i, then remove i to backtrack.
        // Step 4: Avoid duplicates
        // After selecting i, call recursion with i + 1. This ensures each number is used only once and combinations are generated in increasing order
        // Code
        
        vector<vector<int>> ans;
        vector<int> ds;
        Solve(1,ans,ds,k,n);
        return ans;
    }
};