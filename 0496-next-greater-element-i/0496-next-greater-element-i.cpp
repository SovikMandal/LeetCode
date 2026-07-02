class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            int nextGreaterElement = -1;
            int j = 0;
            for(; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    break;
                }
            }

            for(int k = j + 1; k < nums2.size(); k++) {
                if (nums2[k] > nums1[i]) {
                    nextGreaterElement = nums2[k];
                    break;
                }
            }

            ans.push_back(nextGreaterElement);
        }

        return ans;
    }
};