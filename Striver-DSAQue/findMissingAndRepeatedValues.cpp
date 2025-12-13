class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        int expectedSum = total * (total + 1) / 2;

        unordered_set<int> s;
        int actualSum = 0;
        int repeated = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                if (s.count(val)) {
                    repeated = val;   // store once
                } else {
                    s.insert(val);
                }
                actualSum += val;     // always add
            }
        }

        int missing = expectedSum + repeated - actualSum;
        return {repeated, missing};
    }
};
