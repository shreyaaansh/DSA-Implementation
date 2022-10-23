#include<bits/stdc++.h>
using namespace std;

bool NavisSorted(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        for(int j= i+1; j<n; j++)
        {
            if(arr[j] < arr[i])
                return false;
        }
    }
    return true;
}


bool EffisSorted(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        if (arr[i] < arr[i-1])
            return false;

        return true;
    }
}

int main(){
    int arr[] = {5, 12, 30, 2, 35}, n = 5;
      
      printf("%s", NavisSorted(arr, n)? "true": "false");

    return 0;
}