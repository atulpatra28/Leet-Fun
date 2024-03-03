/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int length = 0;
struct ListNode *cur = head;
struct ListNode *temp = head;

// Calculate the length of the list
while (cur != NULL) {
    length++;
    cur = cur->next;
}

cur = head; // Reset cur to head for traversal

// If the node to be removed is the head of the list
if (length == n) {
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Traverse to the node before the nth node from the end
for (int i = 1; i <= length - n - 1; i++) {
    cur = cur->next;        
}

// Update temp to the node to be removed
temp = cur->next;

// Update the pointers to remove the nth node from the end
cur->next = cur->next->next;

// Free memory for the removed node
free(temp);

return head;

}