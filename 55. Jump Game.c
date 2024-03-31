bool canJump(int* nums, int numsSize) {
    int k = 0;
    int furthestReach = 0;
    
    while (k < numsSize && k <= furthestReach) { // Check if k is within the reachable range
        furthestReach = fmax(furthestReach, k + nums[k]); // Update the furthest reachable index
        
        if (furthestReach >= numsSize - 1) // If we can reach the last index or beyond, return true
            return true;
        
        k++; // Move to the next index
    }
    
    return false; // If we can't reach the last index, return false
}
