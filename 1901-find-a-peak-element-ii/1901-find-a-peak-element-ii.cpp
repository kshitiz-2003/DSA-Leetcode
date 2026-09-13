class Solution {
    private:
    int MaxEl(vector<vector<int>>& mat,int n,int m,int col){
        int maxEl=INT_MIN;
        int maxIndex=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxEl){
                maxEl=mat[i][col];
                maxIndex=i;
            }
        }
        return maxIndex;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        //Binary search on column similar to peak element 1
        while(low<=high){
            int mid=low+((high-low)/2);
            int row=MaxEl(mat,n,m,mid);
            int left=mid-1>=0 ? mat[row][mid-1] : -1;
            int right=mid+1<m ? mat[row][mid+1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            //increasing curve
            else if(mat[row][mid]>right) high=mid-1;
            //decreasing curve
            else low=mid+1;
        }
        return {-1,-1};
    }
};