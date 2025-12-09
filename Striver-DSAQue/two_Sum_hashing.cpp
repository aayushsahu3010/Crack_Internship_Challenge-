class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
    int n = nums.size();
    vector<int>ans;
        for(int i =0 ;i<n;i++){
          int   first = nums[i];
          int   sec = target-first;
            if(m.find(sec)!=m.end()){
                 ans.push_back(i);
                 ans.push_back(m[sec]);
            }

            m[first]=i;
        }
    return ans;
    }
};
