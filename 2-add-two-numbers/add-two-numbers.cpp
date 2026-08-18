class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node makes it easier to build the answer
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            int sum = carry;

            // Add digit from l1
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add digit from l2
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Digit to store in current node
            curr->next = new ListNode(sum % 10);

            // Carry for next position
            carry = sum / 10;

            curr = curr->next;
        }

        return dummy->next;
    }
};