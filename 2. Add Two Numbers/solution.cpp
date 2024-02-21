/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = nullptr;
        ListNode* cur = nullptr;
        ListNode* newNode = nullptr;
        int l1_val, l2_val;
        while (l1 != nullptr || l2 != nullptr) {
            newNode = new ListNode;
            newNode->next = nullptr;
            l1 != nullptr ? l1_val = l1->val : l1_val = 0;
            l2 != nullptr ? l2_val = l2->val : l2_val = 0;
            newNode->val = (carry + l1_val + l2_val) % 10;
            carry = (carry + l1_val + l2_val) / 10;

            if (result == nullptr) {
                result = newNode;
            } else {
                cur = result;
                while (cur->next != nullptr) {
                    cur = cur->next;
                }
                cur->next = newNode;
            }

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        if ( carry > 0 ) {
            newNode = new ListNode;
            newNode->val = carry;
            newNode->next = nullptr;
            
            cur = result;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = newNode;
        }

        return result;
    }
};