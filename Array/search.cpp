#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x)
{
    for(int i=0; i<n ; i++)
    {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

int main(){

    int arr[] = {10, 34, 8, 32, 86};
    cout<<search(arr, 5, 10);
    return 0;
}