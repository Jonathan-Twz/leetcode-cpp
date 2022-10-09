class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // offset fast pointer by n
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        
        // if fast move to the end, slow at front of the node to be removed
        while(fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};