// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* middleNode(struct ListNode* head) {
    int length = 0;
    struct ListNode* current = head;
    
        while (current != NULL) {
        length++;
        current = current->next;
    }
        current = head;
    for (int i = 0; i < length / 2; i++) {
        current = current->next;
    }
    
    return current;
}
