bool isPowerOfFour(int n) {
    if (n <= 0) {
        return false; // 0 and negative numbers are not powers of 4
    }

    int ans = log(n) / log(4);
    return pow(4, ans) == n;
}