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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        for(ListNode* t = head; t; t=t->next) len++;
        n = len - n + 1;
        if(n == 1) return head->next;
        
        ListNode* t = head;
        while(n!=2) {
            t = t->next;
            n--;
        }

        ListNode* curr = t->next;
        ListNode* prev = t;

        prev->next = curr->next;
        delete curr;
        return head;
    }
};
