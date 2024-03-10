int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Allocate memory for a hash set to store unique elements of nums1
    bool* set = (bool*)calloc(1001, sizeof(bool)); // Assuming the numbers are in the range [0, 1000]

    // Count unique elements in nums1
    for (int i = 0; i < nums1Size; i++) {
        set[nums1[i]] = true;
    }

    // Allocate memory for the intersection array (maximum possible size)
    int* arr = (int*)malloc(1001 * sizeof(int));
    int k = 0; // Index for the intersection array

    // Iterate through nums2 and check for intersection
    for (int i = 0; i < nums2Size; i++) {
        if (nums2[i] <= 1000 && set[nums2[i]]) {
            arr[k++] = nums2[i];
            set[nums2[i]] = false; // Mark as visited to avoid duplicates
        }
    }

    // Set the size of the intersection array
    *returnSize = k;

    // Free memory allocated for the hash set
    free(set);

    return arr;
}
