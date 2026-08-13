struct ListNode* oddEvenList(struct ListNode* head) {

    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode *odd = head;
    struct ListNode *even = head->next;

    // Save the beginning of even list
    struct ListNode *evenHead = even;

    while (even != NULL && even->next != NULL) {

        // Connect current odd node to next odd node
        odd->next = even->next;
        odd = odd->next;

        // Connect current even node to next even node
        even->next = odd->next;
        even = even->next;
    }

    // Attach even list after odd list
    odd->next = evenHead;

    return head;
}