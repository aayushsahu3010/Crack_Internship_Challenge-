class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Peak is on the right
                low = mid + 1;
            } else {
                // Peak is on the left including mid
                high = mid;
            }
        }

        return low; // low == high -> peak index
    }
};
