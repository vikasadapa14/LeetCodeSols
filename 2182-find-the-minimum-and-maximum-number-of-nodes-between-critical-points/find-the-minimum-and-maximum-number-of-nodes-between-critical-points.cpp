class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        // Need at least 3 nodes
        if (head == nullptr || head->next == nullptr || 
            head->next->next == nullptr) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        int first = -1;
        int last = -1;

        int minDist = INT_MAX;

        while (curr->next != nullptr) {

            ListNode* next = curr->next;

            // Check local maximum or local minimum
            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (isCritical) {

                // First critical point
                if (first == -1) {
                    first = pos;
                }

                // Calculate distance from previous critical point
                if (last != -1) {
                    minDist = min(minDist, pos - last);
                }

                last = pos;
            }

            prev = curr;
            curr = next;
            pos++;
        }

        // Fewer than 2 critical points
        if (first == last) {
            return {-1, -1};
        }

        // Distance between first and last critical points
        int maxDist = last - first;

        return {minDist, maxDist};
    }
};