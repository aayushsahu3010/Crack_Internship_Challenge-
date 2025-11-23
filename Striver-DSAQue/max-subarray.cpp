void printsubarray(vector<int> arr, int n)
{
    for (int st = 0; st < arr.size(); st++)
    {
        for (int et = 0; et < arr.size(); et++)
        {
            for (int i = st; i <= et; i++)
            {
                cout << arr[i];
            }
            cout << " ";
        }
        cout << endl;
    }
}

int maximum_subarray_sum(vector<int> arr)
{

    int maxsum = 0;
    for (int st = 0; st < arr.size(); st++)
    {
        int currsum = 0;
        for (int et = st; et < arr.size(); et++)
        {
            currsum += arr[et];
            maxsum = max(maxsum, currsum);
        }
    }
    return maxsum;
}

int kadanes_algo(vector<int> arr)
{
    int currsum = 0;
    int maxsum = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        currsum += arr[i];
        maxsum = max(currsum, maxsum);
        if (currsum < 0)
        {
            currsum = 0;
        }
    }
    return maxsum;
}
