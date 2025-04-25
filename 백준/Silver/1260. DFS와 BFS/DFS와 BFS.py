# DFS, BFS

import sys

def dfs(graph, start):
    stack = [start]
    visited = []

    while stack:
        node = stack.pop()
        if node not in visited:
            visited.append(node)
            
            for neighbor in sorted(graph[node], reverse=True):
                if neighbor not in visited:
                    stack.append(neighbor)

    for j in visited:
        print(j, end=" ")

def bfs(graph, start):
    queue = [start]
    visited = []

    while queue:
        node = queue.pop(0)
        if node not in visited:
            visited.append(node)

        for neighbor in sorted(graph[node]):
            if neighbor not in visited:
                queue.append(neighbor)

    for j in visited:
        print(j, end=" ")


n, m, v = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n+1)]

for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

dfs(graph, v)
print()
bfs(graph, v)
