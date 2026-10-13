class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        // https://www.youtube.com/watch?v=b5J2CmPEeeQ&t=587s
        // Code
        int MOD=1000000007;
        vector<int> bit(32,0);
        for(int &num:nums){
            for(int b=0;b<=31;b++){
                if(num & (1<<b)){
                    bit[b]++;
                }
            }
        }
        long long result=0;
        while(k){
            long long curr=0;
            for(int b=0;b<=31;b++){
                if(bit[b]>0){
                    curr=(curr | (1<<b));
                    bit[b]--;
                }
            }
            result=(result+(curr*curr))%MOD;
            k--;
        }
        return (int)result;
    }
};