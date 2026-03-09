class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        MOD = 10**9 + 7
        
        dp0 = [[0]*(one+1) for _ in range(zero+1)]
        dp1 = [[0]*(one+1) for _ in range(zero+1)]

        for i in range(1, min(zero, limit)+1):
            dp0[i][0] = 1

        for j in range(1, min(one, limit)+1):
            dp1[0][j] = 1

        for i in range(1, zero+1):
            for j in range(1, one+1):

                for k in range(1, min(i, limit)+1):
                    dp0[i][j] = (dp0[i][j] + dp1[i-k][j]) % MOD

                for k in range(1, min(j, limit)+1):
                    dp1[i][j] = (dp1[i][j] + dp0[i][j-k]) % MOD

        return (dp0[zero][one] + dp1[zero][one]) % MOD