#include<ListNode.hpp>
#include<vector>
#include<iostream>

class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            ListNode* curr;
            std::vector<int> v;
            curr = head;

            while(curr != nullptr) {
                v.push_back(curr->val);
                curr = curr->next;
            }

            std::vector<int>::iterator it1, it2;
            it1 = v.begin();
            it2 = v.end() - 1;
            while(it1 != it2) {
                if(*it1 != *it2) {
                    return false;
                }


                it1++;
                // if it is even, it1 and it2 won't meet at middle
                // manually check
                if (it1 == it2) {
                    break;
                }
                it2--;
            }
            return true;
        }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(10);
    ListNode* curr = head;
    curr->next = new ListNode(22);
    curr = curr->next;
    curr->next = new ListNode(20);
    curr = curr->next;
    curr->next = new ListNode(10);
    curr = curr->next;
    curr->next = nullptr;
    std::cout << s.isPalindrome(head) << std::endl;
    return 0;
}
