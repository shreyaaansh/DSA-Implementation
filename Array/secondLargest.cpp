#include<bits/stdc++.h>
using namespace std;


int getLargestEff(int arr[], int n)
{
    int res = 0;
    for(int i = 1; i<n; i++)
    {
        if(arr[i] > arr[res])
            res = i;
    }
    return res;
}

int secondLargest(int arr[], int n)
{
    int largest = getLargestEff(arr, n);
    int res = -1;
    for(int i = 0; i<n; i++)
    {
        if(arr[i]!= arr[largest])
        {
            if(res = -1)
                res = i;
            else if(arr[i] > arr[res])
                res = i;
        }
    }
    return res;
}

int main ()
{

}