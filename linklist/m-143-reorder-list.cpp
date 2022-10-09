#include <ListNode.h>
#include <stack>

class Solution {
public:
    void reorderList(ListNode* head) {
        //corner cases
        if ((!head) || (!head->next) || (!head->next->next)) return;
        
        // push all nodes to stack s
        std::stack<ListNode*> s;
        ListNode* ptr = head;
        while(ptr) {
            s.push(ptr);
            ptr = ptr->next;
        }
        int size = s.size();
        
        // link head to top of stack(end of linklist), repeat
        ListNode* pptr = head;
        for (int i=0; i<size/2; i++) {
            ListNode* node = s.top();
            s.pop();
            node->next = pptr->next;
            pptr->next = node;
            pptr = pptr->next->next;
        }
        pptr->next = nullptr;
    }
};