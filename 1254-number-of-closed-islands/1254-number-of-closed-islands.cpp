class Solution {
    int m;
    int n;
    private:
    bool DFS(vector<vector<int>>& grid,int r,int c){
        // out of bound
        if(r>=m || c>=n || r<0 || c<0) return false;//not closed
        // if water appears
        if(grid[r][c]==1) return true;//closed hai iss side se
        grid[r][c]=1;//Marked the grid visited
        bool left_closed=DFS(grid,r,c-1);
        bool right_closed=DFS(grid,r,c+1);
        bool up_closed=DFS(grid,r-1,c);
        bool down_closed=DFS(grid,r+1,c);
        return left_closed && right_closed && up_closed && down_closed;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        // Optimal solution
        // https://www.youtube.com/watch?v=dMn6NPk9nPw
        m=grid.size();
        n=grid[0].size();
        int count=0;//Number of Ilands;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    if(DFS(grid,i,j)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};