char* makeGood(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(sizeof(char) * (len + 1)); // Stack to simulate removal of characters
    int top = -1; // Top index of stack

    for (int i = 0; i < len; ++i) {
        if (top >= 0 && abs(stack[top] - s[i]) == 32) { // Checking if characters are of opposite cases
            --top; // Pop from stack if they are opposite cases
        } else {
            stack[++top] = s[i]; // Push the character onto the stack
        }
    }

    stack[top + 1] = '\0'; // Null-terminate the string
    return stack;
}
