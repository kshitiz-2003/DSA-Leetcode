class Solution {
    private:
    //isSafe checking that no two queen colloide while placing
    bool isSafe(int row,int col,vector<string>& board,int n){
        // Checking backward upper diagonal
        int dubrow=row;
        int dubcol=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        // Checking backward Line
        row=dubrow;
        col=dubcol;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        // Checking backward lower diagonal
        row=dubrow;
        col=dubcol;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void Solve(int col,vector<string>& board,vector<vector<string>>& ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){//isSafe checking that no two queen colloide while placing
                board[row][col]='Q';
                Solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        // Recursion and backtracking approach
        // https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=61
        // code
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        Solve(0,board,ans,n);
        return ans;
    }
};