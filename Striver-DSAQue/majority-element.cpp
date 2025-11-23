int optimize_majority_element(vector<int> arr)
{
    int freq = 0, ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (freq == 0)
        {
            ans = arr[i];
        }
        if (ans == arr[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}
