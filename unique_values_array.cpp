#include <iostream>
using namespace std;

void printUnique(int a[], int n){
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=0;j<n;j++)
            if(a[i]==a[j]) c++;
        if(c==1) cout<<a[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    printUnique(a,n);
}
