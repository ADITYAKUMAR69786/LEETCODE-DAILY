class Solution:
    def minOperations(self, s: str) -> int:
        return min(walrus := sum(i%2 == int(s[i]) for i in range(len(s))), len(s) - walrus)