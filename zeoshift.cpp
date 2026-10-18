#include<iostream>
using namespace std;

int main(){
    int arr[] = { 0 , 1 , 0 , 3 , 12};
    int n = 5;

    int i = 0;

    while( i< n){
        if (arr[i] != 0) {

         int j = i;
         while ( j > 0  && arr[j] != 0 && arr[j-1] == 0  ){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
         }
        } 
        i++;
    }

        cout << " the elemts are now:"<<endl;
        for ( int i = 0; i < n ; i ++){
             cout<<"\t"<<arr[i]<<"\n";

        }
    
}