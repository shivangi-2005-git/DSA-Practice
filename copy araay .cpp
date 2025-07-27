#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr1[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    // Create another array to store copy
    int arr2[n];
    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[i]; // copying
    }

    cout << "Copied array: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
