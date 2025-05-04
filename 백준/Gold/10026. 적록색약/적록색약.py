import sys
from collections import deque

sys.setrecursionlimit(100000)
input = sys.stdin.readline

n = int(input())
color_map = [list(input().strip()) for _ in range(n)]

# 방향벡터
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(x, y, visited, grid):
    q = deque()
    q.append((x, y))
    visited[x][y] = True
    target = grid[x][y]

    while q:
        cx, cy = q.popleft()
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if not visited[nx][ny] and grid[nx][ny] == target:
                    visited[nx][ny] = True
                    q.append((nx, ny))

# 구역 수 세는 함수
def count_regions(grid):
    visited = [[False] * n for _ in range(n)]
    count = 0
    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                bfs(i, j, visited, grid)
                count += 1
    return count

# 적록색약용 그리드 만들기: G → R
color_map_blind = [['R' if c == 'G' else c for c in row] for row in color_map]

# 두 결과 출력
print(count_regions(color_map), count_regions(color_map_blind))
