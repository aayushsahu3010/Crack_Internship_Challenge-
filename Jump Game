class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        int n=nums.size()-1;
        for(int i=0;i<=n;i++){
            if(i>maxJump)
                return false;
            maxJump = max(nums[i]+i, maxJump);
        }
        return true;
    }
};
