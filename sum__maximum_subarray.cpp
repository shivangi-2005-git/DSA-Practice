#include <iostream>
#include <climits>
using namespace std;

int kadane(int arr[], int n) {
    int max_so_far = arr[0], curr = arr[0];
    for (int i = 1; i < n; i++) {
        curr = max(arr[i], curr + arr[i]);
        max_so_far = max(max_so_far, curr);
    }
    return max_so_far;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int normal_sum = kadane(arr, n);

    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
        arr[i] = -arr[i];
    }

    int circular_sum = total_sum + kadane(arr, n);

    cout << "Maximum Circular Subarray Sum = " << max(normal_sum, circular_sum) << endl;
    return 0;
}
