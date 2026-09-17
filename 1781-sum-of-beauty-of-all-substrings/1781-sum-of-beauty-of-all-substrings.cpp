class Solution {
public:
    int beautySum(string s) {
        // Optimal Approach
        //Loop through all substrings of the string.
        // Maintain a frequency map of characters for each substring.
        // For each substring:
        // Find the most frequent character's count.
        // Find the least frequent non-zero character's count.
        // Calculate the difference between the two counts.
        // Add the difference to the running sum.
        int sum=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> freq;
            for(int j=i;j<s.size();j++){
                freq[s[j]]++;

            int maxi=INT_MIN;
            int mini=INT_MAX;
            
            for(auto it:freq){
                maxi=max(maxi,it.second);
                mini=min(mini,it.second);
            }
            sum += (maxi-mini);
            }
        }
        return sum;
    }
};