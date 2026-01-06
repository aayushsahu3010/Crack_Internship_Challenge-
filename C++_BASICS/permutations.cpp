
#include <bits/stdc++.h>
using namespace std;

void permutations(vector<int> arr, int idx, vector<vector<int>> &ans)
{
   if (idx == arr.size())
   {
      ans.push_back({arr});
      return;
   }

   for (int i = idx; i < arr.size(); i++)
   {
      swap(arr[idx], arr[i]);
      permutations(arr, idx + 1, ans);
      swap(arr[idx], arr[i]);
   }
}

vector<vector<int>> permutation_array(vector<int> &nums)
{
   vector<vector<int>> ans;
   permutations(nums, 0, ans);
   return ans;
}

void vec_Traversal(vector<vector<int>> ans){
    for (int i = 0; i < ans.size(); i++)
    {
      for (int j = 0; j < ans[i].size(); j++)
      {
        cout<<ans[i][j]<<" ";
      }
      cout<<endl;
      /* code */
    }
    
}

int main()
{
   
   vector<int>arr = {1,2,3};
   vec_Traversal(permutation_array(arr));
   return 0;
}
