class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int maxLength = 0;
        unordered_map<int,int> freq;
        for(int i = 0; i < n; i++) {
            freq[fruits[i]]++;
            while(freq.size() > 2) {
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }

                left++;
            }

            maxLength = max(maxLength, i - left + 1);
        }

        return maxLength;
    }
};