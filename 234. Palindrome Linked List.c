/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

bool isPalindromeUtil(struct ListNode** left, struct ListNode* right) {
    // Base case: if right reaches the end of the list
    if (right == NULL)
        return true;
    
    // Recursively move to the end of the list
    bool isPalindrome = isPalindromeUtil(left, right->next);
    if (!isPalindrome)
        return false;
    
    // Compare values at current positions
    isPalindrome = ((*left)->val == right->val);
    
    // Move left pointer to the next node
    *left = (*left)->next;
    
    return isPalindrome;
}

bool isPalindrome(struct ListNode* head) {
    return isPalindromeUtil(&head, head);
}