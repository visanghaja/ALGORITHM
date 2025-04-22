# sort

import sys

n = int(input())
num = [int(sys.stdin.readline()) for _ in range(n)]
for i in sorted(num):
    print(i)