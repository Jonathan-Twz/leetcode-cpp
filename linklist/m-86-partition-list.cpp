class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        // find the first element larger than X
        while(slow->next!=nullptr && slow->next->val < x){
            slow = slow->next;
        }
        fast = slow;
        // using fast pointer to get smaller element then connect to the slow pointer
        while(fast->next != nullptr){
            if(fast->next->val < x){
                ListNode* temp;
                temp = fast->next;
                fast->next = fast->next->next;
                temp->next = slow->next;
                slow->next = temp;
                slow = temp;
            } else {
                fast = fast->next;
            }
        }
        return dummy->next;
    }
};