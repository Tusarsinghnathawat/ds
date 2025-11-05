#include <iostream>
using namespace std;

#define N 8

// Function to print the board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

// Check if a queen can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this column on upper rows
    for (i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

// Recursive function to solve N-Queen problem
bool solveNQ(int board[N][N], int row) {
    if (row >= N) {
        printBoard(board);
        return true; // found one solution
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            res = solveNQ(board, row + 1) || res; // explore next row
            board[row][col] = 0; // backtrack
        }
    }

    return res;
}

int main() {
    int board[N][N] = {0};
    int firstRow, firstCol;

    cout << "Enter position of first queen (row col, 0-indexed): ";
    cin >> firstRow >> firstCol;

    if (firstRow < 0 || firstRow >= N || firstCol < 0 || firstCol >= N) {
        cout << "Invalid position!" << endl;
        return 0;
    }

    board[firstRow][firstCol] = 1; // Place the first queen

    cout << "\nSolving 8-Queens with first queen at (" << firstRow << ", " << firstCol << "):\n";
    if (!solveNQ(board, firstRow + 1))
        cout << "No solution exists!\n";

    return 0;
}

// Time: O(n^2)