int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int min = -1; // Initialize the minimum value as -1
    int i = 0, j = 0; // Pointers for nums1 and nums2 respectively

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) { // If elements are equal
            if (min == -1 || nums1[i] < min) // Update min if it's uninitialized or if the current element is smaller
                min = nums1[i];
            i++; // Move to the next element in nums1
            j++; // Move to the next element in nums2
        } else if (nums1[i] < nums2[j]) { // If nums1[i] is smaller
            i++; // Move to the next element in nums1
        } else { // If nums2[j] is smaller
            j++; // Move to the next element in nums2
        }
    }
    return min;
}