class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node
        ListNode* dummy = new ListNode(0);

        // temp will build the answer
        ListNode* temp = dummy;

        // Compare both lists
        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        // Attach whichever list is remaining
        if (list1 != nullptr)
            temp->next = list1;
        else
            temp->next = list2;

        return dummy->next;
    }
};