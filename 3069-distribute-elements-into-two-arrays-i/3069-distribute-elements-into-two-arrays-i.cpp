class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        int n = nums.size();
        if(n < 3) return nums;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i = 2; i < n; i++) {
            int n = arr1.size() - 1;
            int m = arr2.size() - 1;
            if(arr1[n] > arr2[m]) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        for(int x : arr2) {
            arr1.push_back(x);
        }

        return arr1;
    }
};