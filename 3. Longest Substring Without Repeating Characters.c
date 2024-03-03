int lengthOfLongestSubstring(char* s) {
    // Determine the length of the string
    int len = strlen(s);

    // Declare an array of characters with enough space to hold the string
    char str[len + 1]; // +1 for the null terminator

    // Copy the characters from the string to the array
    strcpy(str, s);

    int maxlength = 0;
    int sslength = 0;

    // Declare an array to keep track of characters encountered
    int charIndex[256]; // Assuming ASCII characters

    // Initialize all elements of charIndex to -1
    memset(charIndex, -1, sizeof(charIndex));

    int startIndex = 0;

    for (int i = 0; i < len; i++) {
        // Check if the character is already encountered
        if (charIndex[str[i]] >= startIndex) {
            startIndex = charIndex[str[i]] + 1; // Update the start index to the next character after the previous occurrence

        }
        // Update the index of the current character
        charIndex[str[i]] = i;

        // Calculate the length of the current substring without repeating characters
        sslength = i - startIndex + 1;

        // Update the maximum length if needed
        if (sslength > maxlength) {
            maxlength = sslength;
        }
    }

    return maxlength;
}