#include<bits/stdc++.h>
using namespace std;

int MaxSum(int arr[], int n)
{
    int res = arr[0];
    for(int i =0; i<n ; i++)
    {
        int curr = 0;
        for(int j=i; j<n; j++)
        {
            curr = curr + arr[j];
            res = max(res, curr);
        }
    }
    return res;
}

int MaxSumEff(int arr[], int n)
{
    int res = arr[0];
    int maxEnding = arr[0];
    for(int i = 0; i<n; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(maxEnding, res);
    }
return res;
}
int main()
{
    int arr[] = {1, -2, 3, -1, 2}, n = 5;
     cout<<MaxSumEff(arr, n);

    return 0;
}