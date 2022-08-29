/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // corner case for empty ListNode
        if (head == nullptr) return false;
        ListNode * fast = head;
        ListNode * slow = head;

        // fast and slow ptr, finally meets
        while(fast->next != nullptr && fast->next->next != nullptr && slow->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            // if meets, return true
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};