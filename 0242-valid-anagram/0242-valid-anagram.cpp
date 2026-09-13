class Solution {
public:
    bool isAnagram(string s, string t) {
        // OPtimal approach
        // Initialize a frequency array of size 26 (for all uppercase English letters) and set all elements to 0
        // Traverse the first string and increment the frequency of each character.
        // Traverse the second string and decrement the frequency of each character.
        // Finally, check if all elements in the frequency array are zero. If any element is not zero, return false as the characters do not match in frequency.
        // If all frequencies are zero, the strings are anagrams and the function returns true.
        if(s.length()!=t.length()) return false;
        vector<int> arr(26,0);
        for(int i=0;i<s.length();i++){
            //We are Subtracting "A" because 'A' starts with 65 and 'a' sarts with 97 so if we change all character to upper case and then minus 'A'(65) from them then we come into range of 0-25 (range of alphabets in english)
            arr[toupper(s[i])-'A']++;
            arr[toupper(t[i])-'A']--;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0) return false;
        }
        return true;
    }
};