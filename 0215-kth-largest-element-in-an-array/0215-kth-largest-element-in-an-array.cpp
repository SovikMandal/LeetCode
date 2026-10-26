class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // this if for minHeap
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int x : nums) {
            pq.push(x);
            if(pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};