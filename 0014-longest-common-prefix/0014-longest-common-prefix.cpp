class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        //sorting string according to their lexxical order so that we can compare each character
        sort(strs.begin(),strs.end());
        // minimum common string
        string str1=strs[0];
        //maximum common string
        string str2=strs[strs.size()-1];
        //finding minimum index for iterating over str1 and str2
        int minindex=min(str1.size(),str2.size());
        string ans="";
        //checking all common character and returning the substring
        for(int i=0;i<minindex;i++){
            if(str1[i]!=str2[i]) break;
            ans+=str1[i];
        }
        return ans;

    }
};