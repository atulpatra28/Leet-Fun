int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int prod = 1;
    int *result;
    result = (int *)malloc(numsSize * sizeof(int));
    
    // Calculate the product of all elements to the left of i
    for (int i = 0; i < numsSize; i++) {
        result[i] = prod;
        prod *= nums[i];
    }

    prod = 1; // Reset prod to 1

    // Calculate the product of all elements to the right of i and multiply with result[i]
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] *= prod;
        prod *= nums[i];
    }

    *returnSize = numsSize;
    return result;
}