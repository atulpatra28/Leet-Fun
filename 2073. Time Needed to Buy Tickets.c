void decrement_array(int* tickets, int ticketsSize) {
    for (int i = 0; i < ticketsSize; i++) {
        tickets[i] = tickets[i] - 1;
    }
}

int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int time_taken = 0;
    int finished = 0; 
    while (!finished) {
        for (int i = 0; i < ticketsSize; i++) {
            if (tickets[i] > 0) {
                tickets[i]--; 
                time_taken++; 
                if (i == k && tickets[i] == 0) {
                    finished = 1; 
                    break;
                }
            }
        }
    }
    return time_taken;
}