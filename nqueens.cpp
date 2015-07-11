#include <iostream>
#include <vector>

// helper printer
template <class T>
std::ostream & operator<<(std::ostream & out, const std::vector< std::vector<T> > & vec)
{
    for(auto row : vec)
    {
        for(auto x : row)
            out << x << " ";
        out << std::endl;
    }
    return out;
}

// check if valid diagonally
bool CheckDiagonally(const std::vector<std::vector<bool>> & GRID, int size, int row, int col)
{
    // check left, upward diagonal
    for(int i=row, j=col;; --i,--j)
    {
        if(i<0 || j<0)
            break;
        if(GRID[i][j])
            return false;
    }
    
    // check left, downard diagonal
    for(int i=row, j=col;; ++i,--j)
    {
        if(i>=size || j<0)
            break;
        if(GRID[i][j])
            return false;
    }
    
    // check right, upward diagonal
    for(int i=row, j=col;; --i,++j)
    {
        if(i<0 || j>=size)
            break;
        if(GRID[i][j])
            return false;
    }
    
    // check right, downward diagonal
    for(int i=row, j=col;; ++i,++j)
    {
        if(i>=size || j>=size)
            break;
        if(GRID[i][j])
            return false;
    }
    return true;
}

// check if placing in row,col is valid
bool IsSafe(const std::vector<std::vector<bool>> & GRID, int size, int row, int col)
{
    //check in that row
    for(int i=0; i<col; ++i)
    {
        if(GRID[row][i])
            return false;
    }
    return CheckDiagonally(GRID, size, row, col);
}

// our main solver function
bool SolveHelper(std::vector<std::vector<bool>>&GRID, int size, int col)
{
    if(col>=size) return true;

    // in this column, iterate over rows
    for(int i=0; i<size; ++i)
    {
        // if queen can be placed safely
        if(IsSafe(GRID, size, i, col))
        {
            // place in this position
            GRID[i][col] = true;

            // recursion -> place the rest of the queens
            if( SolveHelper(GRID, size, col+1) )
                return true;

            GRID[i][col] = false;
        }
    }
    return false;
}

// main recursive solver
bool Solve(std::vector< std::vector<bool> > & GRID, int size)
{
    //std::cout << IsSafe(GRID, size, 6,3) << std::endl;
    return SolveHelper(GRID, size,0);
}

int main()
{
    int size = 8;
    std::vector< std::vector<bool> > grid(size, std::vector<bool>(size, false));

    if(Solve(grid, size))
        std::cout << grid << std::endl;

    return 0;
}
