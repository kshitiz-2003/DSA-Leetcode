class Solution {
public:
    bool rotateString(string s, string goal) {
      //optimal approach
      //if we double the string s the there exist a substring in double s which is our rotated goal
      // Strings must be the same length to be rotations of each other
      if(s.length()!=goal.length()) return false;
      //doubling the string
      string doubles=s+s;
      //using find() function to know if goal is a substring of doubles or not ,if it is substring it returns index at which goal string start in doubles,if not then it returns string::npos which means string not found
      if(doubles.find(goal)!=string::npos) return true;
      return false;

    }
};