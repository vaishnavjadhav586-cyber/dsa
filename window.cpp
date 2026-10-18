#include<iostream>
using namespace std;

int main(){
    int arr[] = { 2,1,5,1,3,2};
    int n = 6 , k = 3, sum = 0;

    for(int i = 0; i<k ; i ++){
        sum = sum + arr[i];
    }


    float maxsum = (float)sum/k;


    for (int  i = k ; i < n; i++)
    {
        /* code */
        sum = sum - arr[i-k] + arr[i];
        if ( (float)sum/3 < maxsum){
            maxsum = (float)sum/3;
        }
    }
    cout << " The min average sum is now : \n"<<maxsum;

    return 0;}
    