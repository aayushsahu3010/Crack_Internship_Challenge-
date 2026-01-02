#include <bits/stdc++.h>
using namespace std;

bool searchrow(vector<vector<int>> v, int target, int row)
{
    int col = v[0].size();
    int st = 0, end = col - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (target == v[row][mid])
        {
            return 1;
        }
        else if (target > v[row][mid])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return 0;
}

bool searchin2d(vector<vector<int>> v, int target)
{
    int m = v.size();
    int n = v[0].size();
    int start = 0, end = m - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target >= v[mid][0] && target <= v[mid][n - 1])
        {
            return searchrow(v, target, mid);
        }
        else if (target >= v[mid][n - 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return 0;
}

bool search_2d(vector<vector<int>> v, int target)
{
    int row = v.size();
    int col = v[0].size();
    int r = 0, c = col - 1;
    while (c >= 0 && r < row)
    {
        if (target == v[r][c])
        {
            return true;
        }

        if (target < v[r][c])
        {
            c--;
        }
        if (target > v[r][c])
        {
            r++;
        }
    }
}

vector<int> spiral_search(vector<vector<int>> v)
{
    // 4 types of boundary
    // top ,right, bottom , leftm-1
    int row = v.size(), col = v[0].size();
    int srow = 0, scol = 0, erow = row - 1, ecol = col - 1;

    vector<int> ans;
    while (srow <= erow && scol <= ecol)
    {
        for (int j = scol; j <= ecol; j++)
        {
            ans.push_back(v[srow][j]);
        }

        for (int i = srow + 1; i <= erow; i++)
        {
            ans.push_back(v[i][ecol]);
        }

        for (int j = ecol - 1; j >= scol + 1; j--)
        {
            if (srow == erow)
            {
                break;
            }
            ans.push_back(v[erow][j]);
        }

        for (int i = erow - 1; i >= srow + 1; i--)
        {
            if (scol == ecol)
            {
                break;
            }
            ans.push_back(v[i][scol]);
        }
        srow++;
        erow--;
        scol++;
        ecol--;
    }
    return ans;
}

void traversal(vector<int>v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    vector<vector<int>> v = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    vector<vector<int>> v2 = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {

            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << searchin2d(v, 30) << endl;
    cout << search_2d(v2, 19) << endl;
    traversal(spiral_search(v2));
    traversal(spiral_search(v));


    return 0;
}
