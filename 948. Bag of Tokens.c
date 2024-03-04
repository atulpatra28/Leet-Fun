int bagOfTokensScore(int* tokens, int tokensSize, int power) {
    int score = 0;
    int maxScore = 0;
    int i = 0;
    int j = tokensSize - 1;

    // Sort the tokens array (optional step)
    for (int a = 0; a < tokensSize - 1; ++a) {
        for (int b = 0; b < tokensSize - a - 1; ++b) {
            if (tokens[b] > tokens[b + 1]) {
                int temp = tokens[b];
                tokens[b] = tokens[b + 1];
                tokens[b + 1] = temp;
            }
        }
    }

    // Play tokens face-up and face-down
    while (i <= j) {
        // Play face-up if possible
        if (power >= tokens[i]) {
            power -= tokens[i];
            score++;
            maxScore = maxScore > score ? maxScore : score;
            i++;
        } else if (score > 0 && j > i) {
            // Play face-down if score is positive and tokens remain
            power += tokens[j];
            score--;
            j--;
        } else {
            // No valid move, break the loop
            break;
        }
    }

    return maxScore;
}
