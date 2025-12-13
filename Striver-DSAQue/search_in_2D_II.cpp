class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int s = 0;
        int col = matrix[0].size();
        int c = col-1;



        while(s<=row-1 && c >=0){
            
             if(target == matrix[s][c]){ 
                return true;
             }
             else if(target<matrix[s][c]){
                 c--;
             }
             else if(target> matrix[s][c]){
                 s++;
             }
        }
        return false ;
    }
};
