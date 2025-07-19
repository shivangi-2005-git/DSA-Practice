#include <iostream>
using namespace std;

void swapMaxMin(int a[], int n) {
    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[maxIndex]) maxIndex = i;
        if (a[i] < a[minIndex]) minIndex = i;
    }
    int temp = a[maxIndex];
    a[maxIndex] = a[minIndex];
    a[minIndex] = temp;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];     // ✅ pehle sab input lo
    }

    swapMaxMin(a, n);    // ✅ ab ek baar swap karo

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";   // ✅ ek baar print karo
    }
    return 0;
}
