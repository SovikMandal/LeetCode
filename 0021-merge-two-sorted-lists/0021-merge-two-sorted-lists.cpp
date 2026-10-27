/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> nums;
        while(list1 != nullptr) {
            nums.push_back(list1->val);
            list1 = list1 -> next;
        }

        while(list2 != nullptr) {
            nums.push_back(list2->val);
            list2 = list2 -> next;
        }

        sort(nums.begin(), nums.end());
        if (nums.empty()) {
            return nullptr;
        }

        ListNode* head = new ListNode(nums[0]);
        ListNode* mover = head;
        for(int i = 1; i < nums.size(); i++) {
            ListNode* temp = new ListNode(nums[i]);
            mover -> next = temp;
            mover = temp;
        }

        return head;
    }
};