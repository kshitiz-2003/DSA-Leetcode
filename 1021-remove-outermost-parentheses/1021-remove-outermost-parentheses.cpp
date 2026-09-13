class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int level=0;
        for(char ch:s){
            if(ch=='('){
                level++;
                if(level>1) result += ch;
            }
            else if(ch==')'){
                level--;
                if(level>0) result += ch;
            }

        }
        return result;

    }
};