class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        // see this post
        // https://leetcode.com/problems/linked-list-cycle-ii/discuss/1701128/C%2B%2BJavaPython-Slow-and-Fast-oror-Image-Explanation-oror-Beginner-Friendly
        ListNode* slow = head;
        ListNode* fast = head;
        while(true){
            if(fast == nullptr || fast->next == nullptr || fast->next->next == nullptr) return NULL;
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        
        while(fast!=head){
            fast = fast->next;
            head = head->next;
        }
        return head;
    }
};