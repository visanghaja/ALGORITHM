# import sys

# t = int(input())

# for z in range(t):
#     n, m = map(int, sys.stdin.readline().split())
#     lotto = [[0]*(m) for _ in range(n)]
#     lotto[0] = [1] * (m)
    
#     for i in range(1, n):
#         for j in range(1, m):
#             lotto[i][j] = lotto[i][j-1] + lotto[i-1][j // 2]
#     print(lotto[-1][-1])

dp = [[0]*2001 for i in range(11)]
dp[0] = [1]*2001
for i in range(1, 11):
    for j in range(1, 2001):
        dp[i][j] = dp[i][j-1]+dp[i-1][j//2]

T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    print(dp[n][m])