class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		// we will simply return list2.
        if(list1 == NULL)
            return list2;
		
		// if list2 happen to be NULL
		// we will simply return list1.
        if(list2 == NULL)
            return list1;
        
        ListNode* dummy = new ListNode(0);
        ListNode* list=dummy;
        
        // check witch list to put on the results
        while(list1!=nullptr && list2!=nullptr){
            if (list1->val < list2->val){
                list->next = list1;
                list1 = list1->next;
            } else {
                list->next = list2;
                list2 = list2->next;
            }
            list = list->next;
        }
        
        // connect the last part
        if(list1!=nullptr){
            list->next = list1;
        } else {
            list->next = list2;
        }
        return dummy->next;
    }
};