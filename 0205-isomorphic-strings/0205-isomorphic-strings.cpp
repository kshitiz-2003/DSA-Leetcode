class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //as there are 256 ASCII values of alphabets so we use ASCII value as Indext and count their occurance if their occurance is not same then it is not isomorphic
        int m1[256]={0};
        int m2[256]={0};
        int n=s.size();
        for(int i=0;i<n;i++){
            if(m1[s[i]]!=m2[t[i]]) return false;
            //We are doing i+1 becuase we are checking if the change is occuring st same interval or index or not
            m1[s[i]]=i+1;
            m2[t[i]]=i+1;
        }
        return true;
    }
};