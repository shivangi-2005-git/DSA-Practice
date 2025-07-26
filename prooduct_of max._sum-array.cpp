#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int maxProd = arr[0];
    int minProd = arr[0];
    int ans = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) swap(maxProd, minProd);
        maxProd = max(arr[i], maxProd * arr[i]);
        minProd = min(arr[i], minProd * arr[i]);
        ans = max(ans, maxProd);
    }

    cout << "Maximum Product Subarray = " << ans << endl;
    return 0;
}
