import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
graph = [list(map(int, sys.stdin.readline().strip())) for _ in range(n)]

visited = [[[0] * 2 for _ in range(m)] for _ in range(n)]
visited[0][0][0] = 1

dq = deque()

dq.append([0, 0, 0])

dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]

can = False

while dq:
    x, y, w = dq.popleft()

    if x == n-1 and y == m-1:
        can = True
        print(visited[x][y][w])
        exit()

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < n and 0 <= ny < m:
            if graph[nx][ny] == 0 and visited[nx][ny][w] == 0:
                visited[nx][ny][w] = visited[x][y][w] + 1
                dq.append([nx, ny, w])
            elif graph[nx][ny] == 1 and w == 0 and visited[nx][ny][1] == 0:
                visited[nx][ny][1] = visited[x][y][w] + 1
                dq.append([nx, ny, 1])


if not can:
    print(-1)

            

