
bool validMountainArray(int* arr, int arrSize) {
    if (arrSize < 3) // Mountain array must have at least 3 elements
        return false;
    
    int i = 0;
    
    // Walk up the mountain
    while (i < arrSize - 1 && arr[i] < arr[i + 1])
        i++;
    
    // Peak cannot be at start or end
    if (i == 0 || i == arrSize - 1)
        return false;
    
    // Walk down the mountain
    while (i < arrSize - 1 && arr[i] > arr[i + 1])
        i++;
    
    // If we reached the end, it's a valid mountain array
    return i == arrSize - 1;
}