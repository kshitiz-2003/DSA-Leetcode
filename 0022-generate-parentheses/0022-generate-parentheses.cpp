
class Solution {
    private:
    // Checking is parenthesis is valid or not
    bool isValid(string s){
        int balance=0;
        for(char ch:s){
            if(ch=='(') balance++;
            else balance--;
            if(balance<0) return false;
        }
        // More number of closing brackets
        return balance==0;//returns true if balance =0
    }
    // generating all strings
    void generate(vector<string>& ans,string curr,int n){
        if(curr.size()==2*n){
            if(isValid(curr)){
                ans.push_back(curr);
            }
            return;
        }
        generate(ans,curr+"(",n);
        // backtracking is genearting string + ")";
        generate(ans,curr+")",n);

    }
public:
    vector<string> generateParenthesis(int n) {
        // Brute force method 
        // We generate all combination of parenthesis using recursion function
        // Then we chack which combination is valid and store it in our data structure
        vector<string> ans;
        generate(ans,"",n);
        return ans;
    }
};