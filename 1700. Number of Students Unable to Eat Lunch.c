int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    // Initialize counters for each type of sandwich preference
    int count[2] = {0}; // 0 for circular, 1 for square
    
    // Count the number of students for each sandwich preference
    for (int i = 0; i < studentsSize; i++) {
        count[students[i]]++;
    }
    
    // Iterate through sandwiches
    for (int i = 0; i < sandwichesSize; i++) {
        // If there are no more students left with the sandwich preference of the top sandwich,
        // then all remaining students cannot eat
        if (count[sandwiches[i]] == 0) {
            return sandwichesSize - i;
        }
        
        // Remove the student who matches the top sandwich preference
        count[sandwiches[i]]--;
    }
    
    // All students were able to eat
    return 0;
}
