char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    // Calculate the length of the input string
    size_t len = strlen(s);

    // Allocate memory for the answer string
    char* ans = (char*)malloc((len + 1) * sizeof(char)); // +1 for the null terminator
    if (ans == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    ans[0] = '\0'; // Initialize the answer string

    // Traverse the Zigzag pattern and fill characters into ans
    for (int i = 0; i < numRows; i++) {
        int hgt = numRows - i;
        int next = i;
        while (next < len) {
            strncat(ans, &s[next], 1);
            if (hgt == 1) hgt = numRows;
            next += hgt * 2 - 2;
            hgt = numRows - hgt + 1;
        }
    }

    return ans;
}