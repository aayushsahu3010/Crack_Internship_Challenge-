class Solution {
  public:
  
  
  bool isvalid(vector<int> &arr, int k,int n , int mid){
      int student = 1;
      int pages = 0;
      for(int i =0;i<n;i++){
          if(arr[i]>mid){
              return false;
          }
          
          if(pages+arr[i]<=mid){
              pages+=arr[i];
          }
          else{
              student++;
              pages=arr[i];
              
               if(student>k){
          return false ;
      }
          }
          
      }
     
 
         return  true;
      
  }
  
  
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k>n){
            return -1;
        }
        int sum = 0;
        for(int i =0;i<n;i++){
            sum+=arr[i];
        }
        int ans =-1;
        int start =0;
        int end = sum;
        while(start<=end){
            int mid = start+(end-start)/2;
            
            if(isvalid(arr,k,n,mid)){
                               end = mid-1;
                            ans = mid;
                               
            }
            else{
              start = mid+1;
            }
        }
        return ans;
        
    }
};
