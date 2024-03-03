//Here we use the 2 pointers method. 

int* sortedSquares(int* nums, int n, int* returnSize) {
    // Allocate memory for the result array
    int* squares = (int*)malloc(n * sizeof(int));
    if (squares == NULL) { 
        *returnSize = 0;
        return NULL; // Memory allocation failed
    }

    // Initialize pointers for two ends of the array
    int left = 0;
    int right = n - 1;

    // Fill the result array from the end to the beginning
    for (int i = n-1; i >= 0; i--) {
        int square;
        if (abs(nums[left]) > abs(nums[right])) {
            square = nums[left] * nums[left];
            left++;
        } else {
            square = nums[right] * nums[right];
            right--;
        }
        squares[i] = square;
    }

    *returnSize = n; // Set the size of the output array
    return squares;  // Return the pointer to the sorted squares array
}