class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(begin(intervals), end(intervals));

        int n = intervals.size();
        int count = 0;

        int i = 0, j = 1;

        while (j < n) {

            vector<int> curr_interval = intervals[i];
            vector<int> next_interval = intervals[j];

            int cs = curr_interval[0];
            int ce = curr_interval[1];

            int ns = next_interval[0];
            int ne = next_interval[1];

            // No overlap
            if (ce <= ns) {
                i = j;
                j++;
            }

            // Overlap and current interval ends first
            else if (ce <= ne) {
                count++;
                j++;
            }

            // Overlap and next interval ends first
            else {
                count++;
                i = j;
                j++;
            }
        }

        return count;
    }
};