#include <ListNode.h>

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* leftNode=dummy;
        // dummy->next = head;

        for (int i=0; i<left-1; i++) {
            leftNode = leftNode->next;
        }

        ListNode* leftRevNode = leftNode->next;

        for (int i=0; i<right-left ; i++) {
            ListNode* temp = leftNode->next;
            leftNode->next = leftRevNode->next;
            leftRevNode->next = leftRevNode->next->next;
            leftNode->next->next = temp;
        }
        return dummy->next;
    }
};

int main() {
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    Solution s;
    ListNode* head = s.reverseBetween(node1, 2, 4);
    while(head->next) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << head->val << std::endl;
    return 0;
}