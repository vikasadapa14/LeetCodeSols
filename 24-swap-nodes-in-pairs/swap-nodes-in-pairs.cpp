class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        // 0 or 1 node
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* first = head;
        ListNode* second = head->next;

        // Swap the first two nodes
        first->next = swapPairs(second->next);
        second->next = first;

        return second;
    }
};