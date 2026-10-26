class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // we can do this question both approaches maxHeap and minHeap
        unordered_map<int, int> freq;
        for(int x : nums) {
            freq[x]++;
        }

        // here i apply maxHeap 
        priority_queue<pair<int, int>> pq;
        for(auto [key, val] : freq) {
            pq.push({val, key});
        }

        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};