class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Converting a 1D index into 2D index
        //row=index / no of column
        //column=index % no of column
       int low=0;
       int row=matrix.size();
       int col=matrix[0].size();
       int high=(row*col)-1;
       while(low<=high){
        int mid=low+((high-low)/2);
        int i=mid/col;//Finding row;
        int j=mid%col;//Finding column;
        if(matrix[i][j]==target) return true;
        else if(matrix[i][j]>target) high=mid-1;
        else low=mid+1;
       }
       return false;
    }
};