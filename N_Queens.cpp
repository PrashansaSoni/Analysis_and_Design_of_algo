// #include<bits/stdc++.h>
// using namespace std;

// class NQueens{

//     int N;
//     vector<vector<int>>board;

//     public:
//     NQueens(int n){
//         this->N = n;
//         for(int i=0;i<N;i++){
//             for(int j=0;j<N;j++)
//                 board[i][j]=0;
            
//         }
//     }

// void printSolution() {
    
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++)
//             if(board[i][j]==1)
//                 cout << "Q ";
//             else
//                 cout << ". ";
//         cout << "\n";
//     }
// }


// bool isSafe(int row, int col) {
    
//     int i, j;

//     // Check this row on left side
//     for (i = 0; i < col; i++)
//         if (board[row][i])
//             return false;

//     // Check upper diagonal on left side
//     for (i = row, j = col; i >= 0 && 
//          j >= 0; i--, j--)
//         if (board[i][j])
//             return false;

//     // Check lower diagonal on left side
//     for (i = row, j = col; j >= 0 && 
//          i < N; i++, j--)
//         if (board[i][j])
//             return false;

//     return true;
// }


//     bool solveNQUtil( int col) {
//     if (col >= N)
//         return true;

    
//     for (int i = 0; i < N; i++) {

       
//         if (isSafe(i, col)) {

           
//             board[i][col] = 1;

            
//             if (solveNQUtil( col + 1))
//                 return true;

            
//             board[i][col] = 0; // BACKTRACK
//         }
//     }

   
//     return false;
//     }

//   bool SolveNQ(){

//   if (solveNQUtil(0) == false) {
//         cout << "Solution does not exist";
//         return false;
//     }

//     printSolution();
//     return true;

// }
// };



// int main(){
//     int n=4;
//     NQueens Nq(n);

//     Nq.SolveNQ();

// }


#include <iostream>
#include <vector>

class NQueens {
private:
    int N;                              // Board size
    std::vector<std::vector<int>> board; // NxN board representation

    // Utility function to check if it's safe to place a queen at board[row][col]
    bool isSafe(int row, int col) {
        // Check this row on the left side
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 1)
                return false;
        }
        // Check upper diagonal on the left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1)
                return false;
        }
        // Check lower diagonal on the left side
        for (int i = row, j = col; i < N && j >= 0; i++, j--) {
            if (board[i][j] == 1)
                return false;
        }
        return true;
    }

    // Recursive utility function to solve the N-Queens problem
    bool solveNQueens(int col) {
        // Base case: If all queens are placed, return true
        if (col >= N)
            return true;

        // Try placing this queen in all rows one by one
        for (int i = 0; i < N; i++) {
            if (isSafe(i, col)) {  // Check if placing queen here is safe
                board[i][col] = 1; // Place the queen

                // Recursion to place queens in the remaining columns
                if (solveNQueens(col + 1))
                    return true;

                // If placing queen at board[i][col] doesn't lead to a solution, remove it
                board[i][col] = 0;
            }
        }
        return false; // If no placement is possible in this column, return false
    }

public:
    // Constructor to initialize the board and size
    NQueens(int n) : N(n), board(n, std::vector<int>(n, 0)) {}

    // Function to start solving the N-Queens problem
    bool solve() {
        if (!solveNQueens(0)) {
            std::cout << "Solution does not exist.\n";
            return false;
        }
        printSolution();
        return true;
    }

    // Function to print the solution board
    void printSolution() {
        for (const auto& row : board) {
            for (int cell : row) {
                std::cout << (cell == 1 ? "Q " : ". ");
            }
            std::cout << "\n";
        }
    }
};

int main() {
    int n;
    std::cout << "Enter the value of N: ";
    std::cin >> n;
    
    NQueens queens(n);
    queens.solve();

    return 0;
}
