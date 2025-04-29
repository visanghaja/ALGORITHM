# BFS (거리 저장 하면서!)

import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())

maze = [list(map(int, sys.stdin.readline().strip())) for _ in range(n)]

dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]

dq = deque([(0, 0)]) # 튜플로 감싸서

while dq:
    x, y = dq.popleft()
    for i in range(4):
        next_x, next_y = x+dx[i], y+dy[i]
        if 0 <= next_x < n and 0 <= next_y < m:
            if maze[next_x][next_y] == 1:
                dq.append((next_x, next_y))
                maze[next_x][next_y] = maze[x][y] + 1

print(maze[n-1][m-1])