import sys
N, M = map(int, sys.stdin.readline().split())
backet = {}
swap = -1

for i in range(1, N+1):
    backet[i] = i

for j in range(M):
    first, last = map(int, sys.stdin.readline().split())
    swap = backet[first]
    backet[first] = backet[last]
    backet[last] = swap

for p in backet.values():
    print(p, end = " ")