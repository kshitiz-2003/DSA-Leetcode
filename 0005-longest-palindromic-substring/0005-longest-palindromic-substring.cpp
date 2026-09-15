class Solution {
public:
    string longestPalindrome(string s) {
       int n=s.size();
       int start=0;
       int maxlen=1;
        // Traversing through each index
        for(int i=0;i<n;i++){
            // For odd length Palindrome
            int left=i;
            int right=i;
            while(left>=0 && right<n && s[left]==s[right]){
                if((right-left+1)>maxlen){
                    start=left;
                    maxlen=right-left+1;
                }
                left--;
                right++;
            }

            // for even length palindrome
            left=i;
            right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                if((right-left+1)>maxlen){
                    start=left;
                    maxlen=right-left+1;
                }
                left--;
                right++;
            }
        }
        return s.substr(start,maxlen);
    }
};