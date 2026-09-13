class Solution {
public:
    int romanToInt(string s) {
        // We use unordered map to store values of roman characters
        unordered_map<char,int> mpp={
            {'I',1},{'V',5},{'X',10},{'L',50},
            {'C',100},{'D',500},{'M',1000}
        };
        //Traversing through string and finding if s[i]>s[i+1] then we add or if s[i]<s[i-1]then we subtract
        int result=0;
        for(int i=0;i<s.length();i++){
            if(mpp[s[i]]<mpp[s[i+1]]) result -= mpp[s[i]];
            else result+=mpp[s[i]];
        }
        return result;
    }
};