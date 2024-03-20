/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getLength(struct ListNode* head) {
  int count = 0;
  struct ListNode* curr = head;
  while (curr) {
    count++;
    curr = curr->next;
  }
  return count;
}

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
    // Handle edge cases
    if (a <= 0 || !list1 || !list2) {
        return list1;
    }

    // Find the nodes before (prev_a) and after (next_b) the removal range
    struct ListNode* prev_a = list1;
    for (int i = 0; i < a - 1; i++) {
        if (!prev_a->next) {
            // Reached the end of list1 before finding a-th node
            return list1;
        }
        prev_a = prev_a->next;
    }
    struct ListNode* curr = list1;
    for (int i = 0; i < b + 1; i++) {
        if (!curr->next) {
            // Reached the end of list1 before finding b-th node (or b is out of bounds)
            return list1;
        }
        curr = curr->next;
    }
    struct ListNode* next_b = curr;

    // Connect list1 before the removal range with list2
    prev_a->next = list2;

    // Find the end of list2
    struct ListNode* list2_end = list2;
    while (list2_end->next) {
        list2_end = list2_end->next;
    }

    // Connect the end of list2 with the remaining part of list1
    list2_end->next = next_b;

    return list1;
}