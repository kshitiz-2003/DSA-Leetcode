class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // 2. Approach — How should we think?
            // The simplest idea is: keep one path open and block every other cell.

            // Imagine you are designing a maze. You want the person to have exactly one way to reach the destination.

            // We can choose this route:
            // 1. Start at the top-left corner.
            // 2. Move all the way to the right along the first row.
            // 3. Then move down along the last column until you reach the bottom-right corner.
            // 4. Block every other cell with '#'.
            // The route is:
            // - Row 0: move right across all four cells.
            // - Column 3: move down through the remaining rows.
            // Why is there exactly one path?
            // - You cannot move down from the first row before reaching the last column because those cells are blocked.
            // - Once you reach the last column, you must move down to the destination.
            // - Every other possible route is blocked.
            // Therefore, exactly one valid path exists.
        vector<string> grid(m,string(n,'#'));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0) grid[i][j]='.';
                else if(j==n-1) grid[i][j]='.';
            }
        }
        return grid;
    }
};