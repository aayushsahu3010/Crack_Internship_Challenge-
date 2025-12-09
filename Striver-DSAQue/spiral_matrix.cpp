class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int srow = 0, erow = matrix.size()-1;
        int scol = 0, ecol = matrix[0].size()-1;
        vector<int>ans ;
        
        while(srow <= erow && scol <= ecol){ 

            // top
            for(int j = scol ; j <= ecol ; j++){
                ans.push_back(matrix[srow][j]);
            }

            // right
            for(int i = srow+1 ; i <= erow ; i++){
                ans.push_back(matrix[i][ecol]);
            }

            // bottom
            if(srow != erow){
                for(int j = ecol-1 ; j >= scol ; j--){
                    ans.push_back(matrix[erow][j]);
                }
            }

            // left
            if(scol != ecol){
                for(int i = erow-1 ; i >= srow+1 ; i--){
                    ans.push_back(matrix[i][scol]);
                }
            }

            srow++; 
            erow--;
            scol++; 
            ecol--;
        }

        return ans;
    }
};
