void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to find the pivot position
int partition(int *nums, int low, int high) {
    int pivot = nums[high]; // Select the last element as pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; j++) {
        if (nums[j] < pivot) {
            i++;            // Increment index of smaller element
            swap(&nums[i], &nums[j]);
        }
    }
    swap(&nums[i + 1], &nums[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int nums[], int low, int high) {
    if (low < high) {
        int pi = partition(nums, low, high); // Find pivot position

        quickSort(nums, low, pi - 1);  // Recursively sort the left sub-array
        quickSort(nums, pi + 1, high); // Recursively sort the right sub-array
    }
}

// Function to calculate the minimum increments to make array unique
int minIncrementForUnique(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    quickSort(nums, 0, numsSize - 1); // Sort the array first

    int moves = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] <= nums[i - 1]) {
            int target = nums[i - 1] + 1; // Target unique number
            while (nums[i] < target) {    // Ensure nums[i] becomes unique
                nums[i]++;
                moves++;
            }
        }
    }

    return moves;
}