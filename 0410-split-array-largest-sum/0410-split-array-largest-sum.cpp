class Solution {
    private:
    int countsubarray(vector<int>& nums,int maxsum){
        int subarray=1;
        int sumOfElements=0;
        for(int i=0;i<nums.size();i++){
            if((sumOfElements+nums[i])<=maxsum){
                sumOfElements+=nums[i];
            }
            else{
                sumOfElements=nums[i];
                subarray++;
            }
        }
        return subarray;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        //Similar to book allocation problenm
        if(k>nums.size()) return -1;
        int low=*max_element(nums.begin(),nums.end());//if k=nums.size() then maximum sum in all subarray is max element in array
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+((high-low)/2);
            int countSubarray=countsubarray(nums,mid);
            if(countSubarray>k) low=mid+1;//we have to reduce the left half 
            //we can aslo add here ans=mid;
            else{
                high=mid-1;
                //we can aslo add here ans=mid;
            }
        }
        return low;
    }
};