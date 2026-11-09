
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
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;
        for (auto node : lists) {
            if (node != NULL) {
                pq.push({node->val, node});
            }
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ListNode* node = top.second;
            tail->next = node;
            tail = tail->next;
            if (node->next != NULL) {
                pq.push({node->next->val, node->next});
            }
        }
        tail->next = NULL;
        return dummy.next;
    }
};
