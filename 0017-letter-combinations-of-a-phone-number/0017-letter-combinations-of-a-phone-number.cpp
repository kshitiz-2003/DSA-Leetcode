class Solution {
    private:
    void Solve(int ind,string &ds,vector<string>& ans,vector<string> mappings,string& digits){
        if(ind==digits.size()){
            ans.push_back(ds);
            return;
        }
        // character-'0' conversts into integer
        string letter=mappings[digits[ind]-'0'];
        for(char ch:letter){
            ds.push_back(ch);
            Solve(ind+1,ds,ans,mappings,digits);
            ds.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        // Optimal Solution
        // Similar to subset or combination sum1(Using normal method od recursion)
        // The algorithm
        //     1. Create a mapping from each digit to its letters.
        //     2. Start recursion at index 0 with an empty string.
        //     3. If the current combination length equals the number of digits, store it in ans and return.
        //     4. Otherwise, get the letters corresponding to the current digit.
        //     5. For each letter:
        //     - Add the letter to ds.
        //     - Call recursion for the next digit.
        //     - Remove the last letter to explore the next possibility. This is backtracking.
        //     The key line is ds.pop_back(), which undoes the previous choice.
        // Code
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }
        vector<string> mappings={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string ds;
        Solve(0,ds,ans,mappings,digits);
        return ans;
    }
};