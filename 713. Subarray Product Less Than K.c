int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if (numsSize == 0) return 0; 
    
    int count = 0;
    for (int left = 0; left < numsSize; left++) {
        int res = 1; 
        for (int right = left; right < numsSize; right++) {
            res *= nums[right];
            if (res < k) {
                count++;
            } else {
                break; 
            }
        }
    }
    return count;
}