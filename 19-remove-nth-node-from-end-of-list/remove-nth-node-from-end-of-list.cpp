class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Dummy node helps when we need to delete the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both until fast reaches the last node
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the nth node from the end
        slow->next = slow->next->next;

        return dummy->next;
    }
};