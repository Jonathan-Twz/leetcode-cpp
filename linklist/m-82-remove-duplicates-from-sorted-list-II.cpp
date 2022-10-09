class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* ptr = dummy;
        while(ptr->next != nullptr && ptr->next->next!=nullptr){
            // case1: ptr->next and ptr->next->next not same, move to next ptr
            if (ptr->next->val != ptr->next->next->val) {
                ptr = ptr->next;
            } else {
            // case2: ptr->next and ptr->next is same;
                ListNode* pptr=ptr->next;
                while((pptr->next != nullptr)&&(ptr->next->val == pptr->next->val)) {
                    // move to the last of repeated val
                    pptr = pptr->next;
                }
                // point ptr->next to the first not repearted val
                ptr->next = pptr->next;
            }
        }
        return dummy->next;
    }
};