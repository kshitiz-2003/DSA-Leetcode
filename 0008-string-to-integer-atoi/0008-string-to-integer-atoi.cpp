class Solution {
    const int min_val=INT_MIN;
    const int max_val=INT_MAX;
    private:
    int helper(string s,int sign,int i,long long num){
        // base case
        if(i>=s.size() || !isdigit(s[i])){
            return (int)sign * num;
        }
        // Adding the number 
        num=num*10+(s[i]-'0');
        // Checking if the number exceeds the boundary limit of integer
        if(sign*num<min_val) return INT_MIN;
        if(sign*num>max_val) return INT_MAX;

        // Calling recursion function
        return helper(s,sign,i+1,num);

    }
public:
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i]==' ') i++;
        // handling the sign
        int sign=1;
        if(i<s.size() && (s[i]=='+' || s[i]=='-')){
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        
        return helper(s,sign,i,0);
    }
};