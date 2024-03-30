int subarraysWithKDistinct(int* nums, int numsSize, int k) {
    int left1 = 0, left2 = 0;
    int count1 = 0, count2 = 0;
    
    // Find the maximum value in nums
    int maxVal = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    
    int* unique1 = calloc(maxVal + 1, sizeof(int));
    int* unique2 = calloc(maxVal + 1, sizeof(int));
    int result = 0;

    for (int right = 0; right < numsSize; right++) {
        if (unique1[nums[right]] == 0) {
            count1++;
        }
        unique1[nums[right]]++;

        if (unique2[nums[right]] == 0) {
            count2++;
        }
        unique2[nums[right]]++;

        while (count1 > k) {
            unique1[nums[left1]]--;
            if (unique1[nums[left1]] == 0) {
                count1--;
            }
            left1++;
        }

        while (count2 > k - 1) {
            unique2[nums[left2]]--;
            if (unique2[nums[left2]] == 0) {
                count2--;
            }
            left2++;
        }

        result += left2 - left1;
    }

    free(unique1);
    free(unique2);
    return result;
}