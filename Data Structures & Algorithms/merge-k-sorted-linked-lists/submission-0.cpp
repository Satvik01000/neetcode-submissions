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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        ListNode* head = new ListNode();
        ListNode* t = head;

        while (true) {
            int minIdx = -1;
            int minElem = INT_MAX;

            for (int i = 0; i < n; i++) {
                if (lists[i] && lists[i]->val < minElem) {
                    minElem = lists[i]->val;
                    minIdx = i;
                }
            }

            if (minIdx == -1) break;

            t->next = new ListNode(minElem);
            t = t->next;

            lists[minIdx] = lists[minIdx]->next;
        }
        return head->next;
    }
};