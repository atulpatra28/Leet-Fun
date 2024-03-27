//code 1:
int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if (numsSize == 0) return 0; 
    
    int count = 0;
    for (int left = 0; left < numsSize; left++) {
        int res = 1; 
        for (int right = left; right < numsSize; right++) {
            res *= nums[right];
            if (res < k) {
                count++;
            } 
            else 
            {
                break; 
            }
        }
    }
    return count;
}

//code2:
int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if (k <= 1) return 0; // If k is less than or equal to 1, no subarray product can be less than k.

    int count = 0;
    int product = 1;
    int left = 0;

    for (int right = 0; right < numsSize; right++) {
        product *= nums[right];

        while (product >= k) { // Shrink the window from the left until the product is less than k.
            product /= nums[left];
            left++;
        }

        // For each valid right, count the subarrays ending at right.
        count += right - left + 1;
    }

    return count;
}
