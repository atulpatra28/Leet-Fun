class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_set=set()
        right=0
        left=0
        max_len=0
        while right<len(s):
            if s[right] not in char_set:
                char_set.add(s[right])
                right+=1
                max_len=max(max_len,right-left)
            else:
                char_set.remove(s[left])
                left+=1

            return max_len

            