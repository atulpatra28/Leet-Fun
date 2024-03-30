int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int maxArea = 0;

    while (left < right) {
        int area = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
        maxArea = area > maxArea ? area : maxArea;

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}
