class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // code
        // https://www.youtube.com/watch?v=6i_TS0BzTgA
        if(sum>num*9) return "";//if sum=10000  num=2 then even 99 does not give sum=1000 
        int nines=sum/9;
        int remaining=sum%9;
        string result(nines,'9');
        if(remaining>0){
        result.push_back(remaining+'0');//integer+'0' convert into string
        }
        result.append(num-result.size(),'0');
        return result;
    }
};