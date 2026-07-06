class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        int count = 1, maxEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if(intervals[i][1] > maxEnd) {
                count++;
                maxEnd = intervals[i][1];
            }
        }

        return count;
    }
};