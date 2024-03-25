/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int *result = (int*)malloc(numsSize * sizeof(int)); // Allocate memory for result
    *returnSize = 0; // Initialize returnSize to 0
    
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1; // Get the index to mark (subtract 1 because of zero-based indexing)
        
        if (nums[index] < 0) {
            result[(*returnSize)++] = abs(nums[i]); // If the number at index is already negative, it's a duplicate
        } else {
            nums[index] = -nums[index]; // Mark the number at index as seen by negating it
        }
    }
    
    // Restore the array for further use
    for (int i = 0; i < numsSize; i++) {
        nums[i] = abs(nums[i]);
    }
    
    return result;
}
