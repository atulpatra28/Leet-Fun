int maxDepth(char* s) {
    int max_depth = 0;
    int current_depth = 0;

    while (*s != '\0') {
        if (*s == '(') {
            current_depth++;
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
        } else if (*s == ')') {
            current_depth--;
        }
        s++;
    }

    return max_depth;
}