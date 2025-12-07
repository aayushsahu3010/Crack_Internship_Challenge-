class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int n = nums.size();

        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i = 1;i<nums.size();i++){
             if(nums[i-1]!=nums[i]){
                count++;
                temp.push_back(nums[i]);
             }
        }
        nums =temp ;
        return count ;
    }
};
