class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
    
        vector<int>temp ;
        int n1 =a.size();
        int n2 = b.size();
        int i = 0;
        int j =0;
        
        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                temp.push_back(a[i]);
                i++;
            }
            else{
                temp.push_back(b[j]);
                j++;
            }
            
        }
        while(i<n1){
            temp.push_back(a[i]);
            i++;
        }
        while(j<n2){
            temp.push_back(b[j]);
            j++;
        }
        
        vector<int>ans ;
        int t= temp.size();
        ans.push_back(temp[0]);
        for(int i =1;i<t;i++){
            if(temp[i-1]!=temp[i]){
                ans.push_back(temp[i]);
            }
        }
        return ans;
        
    }
};
