#include<bits/stdc++.h>
using namespace std;

int MaxSum(int arr[], int n, int k)
{
    int res = INT_MIN; //intialising it with infinity value
    for(int i=0; i+k-1< n; i++)
    {
        int curr = 0;
        for(int j=0; j<k; j++)
        {
            curr += arr[i+j];
        }
        res = max(res, curr);
    }
}

int MaxKSum(int arr[], int n, int k)
{
    int curr = 0;
    for(int i =0; i<k; i++)
    {
        curr += arr[i];
    }
    int res = curr;
    for(int i = k; i<n; i++)
    {
        curr = curr +arr[i] - arr[i-k];
        res = max(res, curr);
    }
    return res;
}
int main()
{
    int arr[] = {1, 8, 30, -5, 20, 7}, n = 6, k = 3;

     cout<<MaxSum(arr, n, k);
}