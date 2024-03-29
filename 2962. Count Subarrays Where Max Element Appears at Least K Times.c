int findMax(int* nums, int numsSize) {
    int maxVal = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    return maxVal;
}
long long countSubarrays(int* nums, int numsSize, int k) {
    int maxVal = findMax(nums, numsSize);
    long long answer = 0;
    int countMax = 0;
    int j = 0;

    for (int i = 0; i < numsSize; ++i) {
        while (j < numsSize && countMax < k) {
            countMax += nums[j] == maxVal;
            ++j;
        }
        if (countMax < k) break;
        answer += numsSize - j + 1;
        countMax -= nums[i] == maxVal;
    }

    return answer;
}
