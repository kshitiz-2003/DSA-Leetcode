class Solution {
public:
    string largestOddNumber(string num) {
        // Striver's optimal approach
        //finding the first odd number from right side to left side;
        int ind=-1;
        for(int i=num.size()-1;i>=0;i--){
            // num[i]-'0' changes num[i] into integer
            if((num[i]-'0')%2==1){
                ind=i;
                break;
            }
        }
        //removing all zeros
        int i=0;
        while(i<=ind && ((num[i]-'0')==0)) i++;
        //Finding the substring or output
        string result="";
        result=num.substr(i,ind-i+1);
        return result;

    }
};