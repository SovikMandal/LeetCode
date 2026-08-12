class Solution {
public:
    int max_element(vector<int>& arr) {
        int maxVal = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }

        return maxVal;
    }

    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = max_element(candies);
        vector<bool> res;
        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] + extraCandies >= maxCandies) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }

        return res;
    }
};