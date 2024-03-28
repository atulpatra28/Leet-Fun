int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSubarrayLength(int* nums, int numsSize, int k) {
    // Find the maximum value in nums to determine the size of the frequency array
    int maxNum = 0;
    for (int i = 0; i < numsSize; i++) {
        maxNum = max(maxNum, nums[i]);
    }

    // Dynamically allocate memory for the frequency array
    int* freq = (int*)calloc(maxNum + 1, sizeof(int));
    if (freq == NULL) {
        // Error handling for memory allocation failure
        return -1;
    }

    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < numsSize; end++) {
        // Increment the frequency of the current element
        freq[nums[end]]++;

        // Shrink the window if the frequency constraint is violated
        while (freq[nums[end]] > k) {
            freq[nums[start]]--;
            start++;
        }

        // Update the maximum length of the good subarray
        maxLength = max(maxLength, end - start + 1);
    }

    // Free dynamically allocated memory
    free(freq);

    return maxLength;
}
