class Solution {
  public:
  
  bool ispsossible(vector<int>&stalls,int k,int n , int mid){
      int cows = 1;
      int laststall = stalls[0];
      for(int i =0;i<n;i++){
          if(stalls[i]-laststall>=mid){
              cows++;
              laststall = stalls[i];
          }
          
          if(cows==k){
              return true;
          }
      }
      return 0;
  }
  
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n  = stalls.size();
        int s = 1;
        int ans =0;
        int end = stalls[n-1]-stalls[0];
        
        while(s<=end){
            int mid = s+(end-s)/2;
            if(ispsossible(stalls,k,n,mid)){
                ans = mid;
                 s= mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};
