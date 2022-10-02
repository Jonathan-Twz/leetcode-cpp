// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//         ListNode* curr = node;
//         while (curr->next->next != nullptr) {
//             curr->val = curr->next->val;
//             curr = curr->next;
//         }
//         curr->val = curr->next->val;
//         curr->next = nullptr;
//     }
// };

class Solution {
    public:
        void deleteNode(ListNode* node) {
            // change val with next node, then skip the next node
            node->val = node->next->val;
            node->next = node->next->next;
        }
};