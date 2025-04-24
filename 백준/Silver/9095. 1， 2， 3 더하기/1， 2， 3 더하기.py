# DP

n = int(input())
result = []
num = []
num = [int(input()) for _ in range(n)]

maxnum = max(num)
d = [0] * (maxnum + 1)
d[1] = 1
d[2] = 2
d[3] = 4
    
for j in range(4, maxnum + 1):
    d[j] = d[j-1] + d[j-2] + d[j-3]
    
for z in num:
    print(d[z])