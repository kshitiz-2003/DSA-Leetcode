class Solution {
private:
    // comparator return true if we want to place p1 before p2 and returns false if we want to lace p2 before p1
    static bool comp(pair<int, char> p1, pair<int, char> p2) {
        if (p1.first > p2.first)
            return true;
        if (p1.first < p2.first)
            return false;
        return p1.second < p2.second;
    }

public:
    string frequencySort(string s) {
        // optima approach of finding the frequescy of each digit then sorting
        // it accordingly then return the string
        // counting the frequency
        int freq[256] = {0};
        for (char ch : s) {
            freq[(unsigned char)ch]++;
        }

        vector<pair<int, char>> arr;
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                arr.push_back({freq[i], (char)i});
            }
        }
        // Sorting according to their frequency
        sort(arr.begin(), arr.end(), comp);

        string result = "";
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 1; j <= arr[i].first; j++) {
                result += arr[i].second;
            }
        }
        return result;
    }
};