int maxFrequencyElements(int* nums, int numsSize) {
    int freq_dict[101]; // Initialized with the maximum possible value
    memset(freq_dict, 0, sizeof(freq_dict));  // Initialize all elements to 0

    int max_freq = 0;
    int max_value = INT_MIN; // Initialize with minimum possible value
    for (int i = 0; i < numsSize; i++) {
        max_value = fmax(max_value, nums[i]); // Find the actual maximum element
        max_freq = fmax(max_freq, ++freq_dict[nums[i]]); // Update max_freq and increment frequency
    }

    int count = 0;
    for (int i = 1; i <= max_value; i++) {
        if (freq_dict[i] == max_freq) {
            count += max_freq; // Add the frequency to count
        }
    }

    return count;
}