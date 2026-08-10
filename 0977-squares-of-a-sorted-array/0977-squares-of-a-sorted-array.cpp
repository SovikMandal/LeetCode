class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares_arr;
        for(int x : nums) {
            squares_arr.push_back(x*x);
        }

        sort(squares_arr.begin(), squares_arr.end());
        return squares_arr;
    }
};