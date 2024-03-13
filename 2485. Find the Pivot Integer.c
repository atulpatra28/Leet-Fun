int pivotInteger(int n) {
    int total_sum = (n * (n + 1)) / 2; // Sum of integers from 1 to n
    int left_sum = 0;

    for (int x = 1; x <= n; x++) {
        left_sum += x;
        int right_sum = total_sum - left_sum + x; // Adjusting for inclusive sum

        if (left_sum == right_sum) {
            return x;
        }
    }

    return -1;    
}