/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return; // Nothing to reorder

    // Find the middle of the linked list
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    struct ListNode *prev = NULL;
    struct ListNode *curr = slow->next;
    while (curr != NULL) {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    slow->next = NULL;

    // Merge the two halves
    struct ListNode *first = head;
    struct ListNode *second = prev;
    while (first != NULL && second != NULL) {
        struct ListNode *first_next = first->next;
        struct ListNode *second_next = second->next;
        first->next = second;
        second->next = first_next;
        first = first_next;
        second = second_next;
    }
}
// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}