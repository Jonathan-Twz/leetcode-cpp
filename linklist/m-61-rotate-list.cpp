class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        ListNode* p = dummy;
        int q=0;
        // corner cases;
        if (k==0 || dummy->next == nullptr) {
            return dummy->next;
        }
        
        // get linklist length
        while(p->next != nullptr){
            p=p->next;
            q++;
        }
        
        // offset fast pointer of k
        for (int i=0; i<k%q; i++){
            fast = fast->next;
        }
        
        // move fast and slow pointer
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        
        // re-link the linknode
        fast->next = dummy->next;
        dummy->next = slow->next;
        slow->next = nullptr;
        return dummy->next;        
    }
};