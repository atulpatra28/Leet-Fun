int trap(int* height, int heightSize) {
    if (height == NULL || heightSize <= 2)
        return 0;
    
    int left = 0, right = heightSize - 1;
    int maxLeft = 0, maxRight = 0;
    int waterTrapped = 0;
    
    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= maxLeft)
                maxLeft = height[left];
            else
                waterTrapped += maxLeft - height[left];
            left++;
        } else {
            if (height[right] >= maxRight)
                maxRight = height[right];
            else
                waterTrapped += maxRight - height[right];
            right--;
        }
    }
    
    return waterTrapped;
}
