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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr_ = head;
        ListNode* prev_ = nullptr;
        ListNode* next_ = nullptr;
        
        while(curr_ != nullptr) {
            next_ = curr_->next;
            curr_->next = prev_;
            prev_ = curr_;
            curr_ = next_;
        }
        return prev_;
    }
};