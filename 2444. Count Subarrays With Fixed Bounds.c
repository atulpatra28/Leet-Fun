// Custom max function for integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Custom min function for integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

long long countSubarrays(int* nums, int numsSize, int minK, int maxK) {
    long long count = 0;
    int lastMinIndex = -1; // Index of the last occurrence of minK
    int lastMaxIndex = -1; // Index of the last occurrence of maxK
    int lastIndexOutsideRange = -1; // Index of the last number that is outside the [minK, maxK] range

    for (int i = 0; i < numsSize; ++i) {
        // If current element is outside the [minK, maxK] range, update the index
        if (nums[i] < minK || nums[i] > maxK) lastIndexOutsideRange = i;
        // If current element equals minK, update the index of the last occurrence of minK
        if (nums[i] == minK) lastMinIndex = i;
        // If current element equals maxK, update the index of the last occurrence of maxK
        if (nums[i] == maxK) lastMaxIndex = i;

        // Count subarrays ending at index i which have minK and maxK within them
        count += max(0, min(lastMinIndex, lastMaxIndex) - lastIndexOutsideRange);
    }

    return count;
}
