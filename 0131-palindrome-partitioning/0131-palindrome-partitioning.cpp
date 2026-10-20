class Solution {
    private:
    bool isPalindrome(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void Solve(int ind,vector<string>& ds,vector<vector<string>>& ans,string& s){
        if(ind==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                ds.push_back(s.substr(ind,i-ind+1));
                Solve(i+1,ds,ans,s);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        // Recursive steps(Combi9nation sum 2 ki tarah hai baas modified hai bohot)
        // 1. Start with ind = 0.
        // 2. Run a loop from i = ind to s.size() - 1.
        // 3. Extract the substring s.substr(ind, i - ind + 1).
        // 4. If the substring is a palindrome:
        // - Add it to ds.
        // - Recursively solve the remaining string, starting at i + 1.
        // - Remove the substring from ds to backtrack and explore other choices.
        // 5. When ind == s.size(), add ds to the answer.
        // Important: We only make a recursive call when the chosen substring is a palindrome.
        // Code
        vector<vector<string>> ans;
        vector<string> ds;
        Solve(0,ds,ans,s);
        return ans;
    }
};