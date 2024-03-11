char* customSortString(char* order, char* s) {
    // Count the frequency of characters in s
    int frequency[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        frequency[s[i] - 'a']++;
    }

    // Construct the sorted string
    int index = 0;
    for (int i = 0; i < strlen(order); i++) {
        while (frequency[order[i] - 'a'] > 0) {
            s[index++] = order[i];
            frequency[order[i] - 'a']--;
        }
    }

    // Append any remaining characters from s
    for (int i = 0; i < 26; i++) {
        while (frequency[i] > 0) {
            s[index++] = 'a' + i;
            frequency[i]--;
        }
    }

    return s;
}