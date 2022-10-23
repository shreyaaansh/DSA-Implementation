#include<bits/stdc++.h>
using namespace std;

void moveToEndEff(int arr[], int n)
{
    for(int i = 0; i<n ; i++)
    {
        if(arr[i] == 0)
        {
            for(int j = i+1; j<n; j++)
            {
                if(arr[j] != 0)
                    swap(arr[i], arr[j]);
            }
        }
    }
}



void moveToZerosEff(int arr[] , int n)
{
    int count = 0 ;
    for(int i = 0; i<n; i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}


int main(){
     int arr[] = {10,5,0,0,8,0,9,0}, n = 8;

      cout<<"Before Removing zero"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }

       cout<<endl;

       moveToEndEff(arr, n);

       cout<<"After Removing zero"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }

    return 0;
}