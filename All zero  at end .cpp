#include <iostream>
using namespace std;

int main(){
    int arr[] = {0,1,2,0,3,4,0,5,6,0,7,8,0,9,0,};
    int n = sizeof(arr)/sizeof(arr[0]);
    int j = 0;

    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            arr[j++] = arr[i];
        }
    }
    while(j<n){
        arr[j++] = 0;
    }

    cout<<"After moving zeroes: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
