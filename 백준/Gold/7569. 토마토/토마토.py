import sys
from collections import deque

m, n, h = map(int, sys.stdin.readline().split())
box = [[list(map(int, sys.stdin.readline().split())) for _ in range(n)] for __ in range(h)]

dx, dy, dz = [0, 0, -1, 1, 0, 0], [0, 0, 0, 0, 1, -1], [1, -1, 0, 0, 0, 0]
dq = deque()

for i in range(h):
    for j in range(n):
        for z in range(m):
            if box[i][j][z] == 1:
                dq.append([i, j, z])

while dq:
    z, y, x = dq.popleft()
    for i in range(6):
        nx = x + dx[i]
        ny = y + dy[i]
        nz = z + dz[i]

        if 0 <= nx < m and 0 <= ny < n and 0 <= nz < h:
            if box[nz][ny][nx] == 0:
                box[nz][ny][nx] = box[z][y][x] + 1
                dq.append([nz, ny, nx])
days = 0
for z in range(h):
    for y in range(n):
        for x in range(m):
            if box[z][y][x] == 0:
                print(-1)
                exit()
            days = max(days, box[z][y][x])

print(days - 1)