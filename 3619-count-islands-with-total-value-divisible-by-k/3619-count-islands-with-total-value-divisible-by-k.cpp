class Solution {
    int n;
    int m;
private:
 long long DFS(int r,int c,vector<vector<int>>& grid){
        long long sum=grid[r][c];
        grid[r][c]=0;//Marked visited (this is doing once in entire iteration)
        // DFS downward
        if(r+1<n && grid[r+1][c]!=0){
            sum=sum+DFS(r+1,c,grid);
        }
        // DFS left
        if(c-1>=0 && grid[r][c-1]!=0){
            sum=sum+DFS(r,c-1,grid);
        }
        // DFS right
        if(c+1<m && grid[r][c+1]!=0){
            sum=sum+DFS(r,c+1,grid);
        }
        // DFS upward
        if(r-1>=0 && grid[r-1][c]!=0){
            sum=sum+DFS(r-1,c,grid);
        }
        return sum;
 }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        // Optimal recursion and backtracking Solution
        // https://www.youtube.com/watch?v=xAMQP-em79w
        n=grid.size();
        m=grid[0].size();
        long long sum;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    sum=DFS(i,j,grid);
                    if(sum%k==0) count++;
                }
            }
        }
        return count;
    }
};