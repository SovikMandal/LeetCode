class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> v;
        for(int i = 0; i < points.size(); i++) {
            int distance = abs(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            v.push_back({distance, i});
        }

        sort(v.begin(), v.end());

        vector<vector<int>> ans;
        for(int i = 0; i < v.size(); i++) {
            if(k != 0) {
                ans.push_back(points[v[i].second]);
                k--;
            } else {
                break;
            }
        }

        return ans;
    }
};