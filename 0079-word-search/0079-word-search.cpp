class Solution {
    private:
    bool Solve(int ind,int r,int c,vector<vector<char>>& board,string& word){
        if(ind==word.size()){
            return true;
        }
        int m=board.size();
        int n=board[0].size();
        if(r<0 || c<0 || r>=m || c>=n){
            return false;
        }
        if(board[r][c]!=word[ind]) return false;
        // Store the character and mark cell visited
        char ch=board[r][c];
        board[r][c]='#';
        // Recursion calling to check if word is forming or not in left,right,upward,downward position
        bool found=(
            // Moving down
            Solve(ind+1,r+1,c,board,word) ||
            // Moving upward
            Solve(ind+1,r-1,c,board,word) ||
            // Moving left
            Solve(ind+1,r,c-1,board,word) ||
            // Moving right
            Solve(ind+1,r,c+1,board,word) 
        );
        // Backtracking
        board[r][c]=ch;
        return found;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        // 2. Approach — Recursion and Backtracking
            // The main idea is to start from every cell and recursively search for the next character of the word.
            // Step 1: Try every cell
            // Suppose the word is "ABCCED".

            // We search the grid for the first character, 'A'. Whenever we find an 'A', we start exploring from that cell.
            // Step 2: Check the current character
            // We create a recursive function:
            // bool Solve(int r, int c, int ind, ...)


            // - r = current row
            // - c = current column
            // - ind = index of the character we are searching for in word
            // For example, if ind = 2, we need to find word[2], which is 'C'.
            // Step 3: Base case
            // If we have matched every character in word, return true.
            // if (ind == word.size()) {
            //     return true;
            // }


            // Step 4: Check invalid conditions
            // Return false if:
            // - We move outside the grid.
            // - The current cell does not match word[ind].
            // - We try to reuse a cell already present in the current path.
            // Step 5: Explore four directions
            // After matching the current character, explore all four neighboring cells.
            //             UP
            //             ↑
            //     LEFT ← CURRENT → RIGHT
            //             ↓
            //             DOWN


            // Before exploring neighbors, mark the current cell as visited. After recursion, restore its original character. This restoration is the backtracking step.
        // code
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(Solve(0,i,j,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};