class Solution:
    def decimal_to_binary(self, number):
        binary = ""
        if number == 0:
            return "0"
        while number > 0:
            binary = str(number % 2) + binary
            number = number // 2
        return binary

    def minBitFlips(self, start: int, goal: int) -> int:
        # Convert both start and goal to binary
        start_bin = self.decimal_to_binary(start)
        goal_bin = self.decimal_to_binary(goal)

        # Pad the shorter string with leading zeros to match their lengths
        max_len = max(len(start_bin), len(goal_bin))
        start_bin = start_bin.zfill(max_len)
        goal_bin = goal_bin.zfill(max_len)

        # Initialize a counter for the number of flips
        count = 0

        # Compare the two binary strings bit by bit
        for i in range(max_len):
            if start_bin[i] != goal_bin[i]:
                count += 1  # Increment the count if the bits are different

        return count


##better approach
