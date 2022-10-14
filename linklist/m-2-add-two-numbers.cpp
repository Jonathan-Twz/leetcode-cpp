class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {   
        int addon = 0;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(l1||l2||addon){
            int value = 0;
            if (l1){
                value += l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                value += l2->val;
                l2 = l2->next;
            }
            
            value += addon;
            addon = value/10;
            value = value%10;
            curr->next = new ListNode(value);
            curr = curr->next;
        }
        return dummy->next;
    }
};