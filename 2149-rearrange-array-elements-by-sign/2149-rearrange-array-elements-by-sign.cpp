class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> pos;
        vector<int> neg;

        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) pos.push_back(arr[i]);
            else if(arr[i] < 0) neg.push_back(arr[i]);
        }

        vector<int> result(n, -1);
        int j = 0;
        for(int i = 0; i < n; i += 2) {
            result[i] = pos[j];
            j++;
        }

        int k = 0;
        for(int i = 1; i < n; i += 2) {
            result[i] = neg[k];
            k++;
        }

        return result;
    }
};