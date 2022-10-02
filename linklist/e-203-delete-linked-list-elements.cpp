#include <ListNode.hpp>

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head;
        // DUMMY NODE!!!
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        while(curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                // move prev first
                prev = curr;
                curr = curr->next;
            }
        }
        // if return head, then its probably
        // the null list, if using dummy ->next, it can avoid the 
        // situation that the first element is empty
        return dummy.next;
    }
};