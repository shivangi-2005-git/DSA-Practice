class Solution {
public:
    int bestClosingTime(string customers) {
       
        int n = customers.size();

        int penalty = 0;

        // Closing at hour 0
        for (char ch : customers) {
            if (ch == 'Y')
                penalty++;
        }

        int minPenalty = penalty;
        int answer = 0;

        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y')
                penalty--;  // customer served, penalty decreases
            else
                penalty++;  // open but no customer

            if (penalty < minPenalty) {
                minPenalty = penalty;
                answer = i + 1;
            }
        }

        return answer;
    }


};