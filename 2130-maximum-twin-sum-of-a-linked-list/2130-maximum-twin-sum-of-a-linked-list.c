int pairSum(struct ListNode* head) {

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Find the middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode *prev = NULL;
    struct ListNode *curr = slow;

    while (curr != NULL) {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Compare first half with reversed second half
    int maxSum = 0;

    struct ListNode *first = head;
    struct ListNode *second = prev;

    while (second != NULL) {
        int sum = first->val + second->val;

        if (sum > maxSum)
            maxSum = sum;

        first = first->next;
        second = second->next;
    }

    return maxSum;
}