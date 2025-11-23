pair<int, int> parisum(vector<int> arr, int target)
{
    int i = 0;
    int j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == target)
        {
            return make_pair(i, j);
        }
        else if ((arr[i] + arr[j]) < target)
        {
            i++;
        }
        else if ((arr[i] + arr[j]) > target)
        {
            j--;
        }
    }
    return make_pair(-1, -1);
}
