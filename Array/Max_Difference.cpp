#include<bits/stdc++.h>
using namespace std;

int maxDiffNav(int arr[], int n)
{
    int res = arr[1] - arr[0];
    for (int i =0 ;i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
            res = max(res, arr[j] - arr[i]);
    }
    return res;
}


int maxDiffEff(int arr[], int n)
{
    int res = arr[1] - arr[0], minVal = arr[0];
    for(int i = 0; i < n; i++)
    {
        res = max(res, arr[i] - minVal);
        minVal = min(minVal, arr[i]);
    }
}
int main()
{
    int arr[] = {2, 3, 10, 6, 4, 8, 1}, n = 7;

    cout<<maxDiffEff(arr, n);
    
    return 0;
}