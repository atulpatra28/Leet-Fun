//Using Hash Set

int findDuplicate(int* nums, int numsSize) {
    bool *seen = (bool*)calloc(numsSize, sizeof(bool));
    
    for (int i = 0; i < numsSize; i++) {
        if (seen[nums[i]]) {
            free(seen);
            return nums[i];
        }
        seen[nums[i]] = true;
    }
    
    free(seen);
    return -1; // No duplicate found
}