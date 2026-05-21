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
    void reorderList(ListNode* head) {
        if(!head->next) return;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow->next, *prev = nullptr;
        slow->next = nullptr;

        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode *t = head, *k = prev;
        bool flag = true;
        while(t && k) {
            ListNode* temp = nullptr;
            if(flag) {
                temp = t->next;
                t->next = k;
                t = temp;
                flag = false;
            } else {
                temp = k->next;
                k->next = t;
                k = temp;
                flag = true;
            }
        }
    }
};
