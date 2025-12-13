class Solution {
public:
    bool searchrow(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();
        int s = 0;
        int e = n - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (target == matrix[row][mid]) {
                return true;
            } else if (target >= matrix[row][mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return false;
    }
    bool search(vector<vector<int>>& matrix, int target) {
        int s = 0;
        int n = matrix[0].size();
        int m = matrix.size();
        int end = m - 1;
        if (matrix[0][0] == target || matrix[m - 1][n - 1] == target) {
            return true;
        } else {
            while (s <= end) {
                int mid = s + (end - s) / 2;
                if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {

                    return searchrow(matrix, target, mid);
                } else if (target > matrix[mid][n - 1]) {
                    s = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return search(matrix, target);
    }
};
