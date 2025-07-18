#include  <iostream>
using namespace std;
int main(){

    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);


    int  first=INT_MIN , second=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > first) {
            second = first;

            first = arr[i];
    }
    else if(arr[i] > second && arr[i] !=first){
        second = arr[i];
    }       

}
cout<<"second largest element="<<second<<endl;
return 0;
}