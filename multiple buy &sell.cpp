#include <iostream>
#include <vector>
using namespace std;

int maxProfitMultiple(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1]; // add positive difference
        }
    }
    return profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit (Multiple Transactions): " << maxProfitMultiple(prices) << endl;
    return 0;
}
