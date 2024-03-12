/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* current = head;
    struct ListNode* prev = &dummy;
    
    while (current != NULL) {
        int sum = 0;
        struct ListNode* temp = current;
        while (temp != NULL) {
            sum += temp->val;
            if (sum == 0) {
                prev->next = temp->next;
                current = prev->next;
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL) {
            prev = current;
            current = current->next;
        }
    }
    
    return dummy.next;
}