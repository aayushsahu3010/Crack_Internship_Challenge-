#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {

        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig) {
                return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig) {
                return false;
            }
        }

        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;

        for (int i = srow; i <=srow + 2; i++) {
            for (int j = scol; j <=scol + 2; j++) {
                if (board[i][j] == dig) {
                    return false;
                }
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {

        int nextrow = row;
        int nextcol = col + 1;

        if (row == 9) {
            return true;
        }

        if (nextcol == 9) {
            nextrow = row + 1;
            nextcol = 0;
        }

        if (board[row][col] != '.') {
           return helper(board, nextrow, nextcol);
        }

        for (char i = '1'; i <= '9'; i++) {
            if (isSafe(board, row, col, i)) {
                board[row][col] = i;
                if (helper(board, nextrow, nextcol)) {
                    return true;
                }
                board[row][col] = '.';
            }

            /* code */
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) { helper(board, 0, 0); }
};
