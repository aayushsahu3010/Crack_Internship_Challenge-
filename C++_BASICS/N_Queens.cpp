#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>&board, int row, int n, int col)
{
    // horizontal
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
        {

            return false;
            /* code */
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
            /* code */
        }

        /* code */
    }
    return true;
}

void nqueen(vector<string> &board, int row, int n, vector<vector<string>>& ans)
{
    if (row == n)
    {
        ans.push_back({board});
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, n, j))
        {
            board[row][j] = 'Q';
            nqueen(board, row + 1, n, ans);
            board[row][j] = '.';   // BACKTRACK
        }
    }
}

vector<vector<string>> solveNqueen(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    nqueen(board, 0, n, ans);
    return ans;
}

void vec_Traversal(const vector<vector<string>>& ans)
{
    int sol = 1;
    for (const auto& board : ans)
    {
        cout << "Solution " << sol++ << ":\n";
        for (const auto& row : board)
        {
            for (char cell : row)
                cout << cell << " ";
            cout << '\n';
        }
        cout << "------------------\n";
    }
}


int main()
{

    cout << "hello world" << endl;
    vec_Traversal(solveNqueen(5));
    return 0;
}
