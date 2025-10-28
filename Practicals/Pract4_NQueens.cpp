#include <iostream>
#include <vector>
using namespace std;

class NQueens
{
private:
    int N;
    vector<vector<int>> board;

    // Check if a queen can be placed on board[row][col]
    bool isSafe(int row, int col)
    {
        // Check this row on left side
        for (int j = 0; j < col; j++)
            if (board[row][j])
                return false;

        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j])
                return false;

        // Check lower diagonal on left side
        for (int i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j])
                return false;

        return true;
    }

    // Recursive utility function to solve N Queen problem
    bool solveNQUtil(int col)
    {
        // Base case: If all queens are placed, return true
        if (col >= N)
            return true;

        // Consider this column and try placing this queen in all rows one by one
        for (int i = 0; i < N; i++)
        {
            // Check if queen can be placed on board[i][col]
            if (isSafe(i, col))
            {
                // Place this queen in board[i][col]
                board[i][col] = 1;

                // Recur to place rest of the queens
                if (solveNQUtil(col + 1))
                    return true;

                // If placing queen in board[i][col] doesn't lead to a solution,
                // then remove queen from board[i][col]
                board[i][col] = 0; // Backtrack
            }
        }

        // If queen can't be placed in any row in this column col, return false
        return false;
    }

public:
    NQueens(int n) : N(n)
    {
        board.resize(n, vector<int>(n, 0));
    }

    // Solve the N Queen problem using Backtracking
    bool solveNQ()
    {
        if (solveNQUtil(0) == false)
        {
            cout << "Solution does not exist" << endl;
            return false;
        }

        printSolution();
        return true;
    }

    // Print the solution
    void printSolution()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j])
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    }

    // Function to solve and print multiple solutions
    void findAllSolutions(int col = 0, int &solutionCount = *(new int(0)))
    {
        // Base case: If all queens are placed, print the solution
        if (col >= N)
        {
            cout << "\nSolution " << ++solutionCount << ":\n";
            printSolution();
            return;
        }

        // Try placing queen in all rows of current column
        for (int i = 0; i < N; i++)
        {
            if (isSafe(i, col))
            {
                board[i][col] = 1;
                findAllSolutions(col + 1, solutionCount);
                board[i][col] = 0; // Backtrack
            }
        }
    }
};

int main()
{
    int n = 4; // Change this to solve for different board sizes
    NQueens nQueens(n);

    cout << "Solutions for " << n << "-Queens Problem:\n";
    int solutionCount = 0;
    nQueens.findAllSolutions(0, solutionCount);

    if (solutionCount == 0)
    {
        cout << "No solutions exist for " << n << "-Queens Problem" << endl;
    }
    else
    {
        cout << "\nTotal number of solutions: " << solutionCount << endl;
    }

    return 0;
}