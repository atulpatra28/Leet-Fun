int romanToInt(char *s) {
    int num = 0;
    int i = 0;

    // Loop through each character in the string
    while (s[i]) {
        // Check for special cases
        if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
            num -= 1;
        } else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
            num -= 10;
        } else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
            num -= 100;
        } else {
            // Add corresponding value of the character to num
            switch (s[i]) {
                case 'I':
                    num += 1;
                    break;
                case 'V':
                    num += 5;
                    break;
                case 'X':
                    num += 10;
                    break;
                case 'L':
                    num += 50;
                    break;
                case 'C':
                    num += 100;
                    break;
                case 'D':
                    num += 500;
                    break;
                case 'M':
                    num += 1000;
                    break;
                default:
                    printf("Invalid Roman numeral.\n");
                    return -1; // Return -1 if invalid input
            }
        }
        i++;
    }
    return num;
}