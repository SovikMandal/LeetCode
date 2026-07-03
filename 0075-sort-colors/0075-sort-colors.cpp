class Solution {
public:
    void sortColors(vector<int>& arr) {
        int left = 0;
        int curr = 0;
        int right = arr.size() - 1;

        while(curr <= right) {
            if(arr[curr] == 0) {
                swap(arr[curr], arr[left]);
                left++;
                curr++;
            }

            else if(arr[curr] == 2) {
                swap(arr[curr], arr[right]);
                right--;
            }

            else {
                curr++;
            }
        }
    }
};