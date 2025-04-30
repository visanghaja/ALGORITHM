# DP

import sys

n, k = map(int, sys.stdin.readline().split())

thing = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

val = [[0] * (k + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(k + 1):
        if thing[i-1][0] <= j:
            val[i][j] = max(val[i-1][j], val[i-1][j-thing[i-1][0]] + thing[i-1][1])
        else:
            val[i][j] = val[i-1][j]

print(val[-1][-1])