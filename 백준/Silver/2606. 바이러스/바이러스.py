import sys

com = int(input())
pair = int(input())

graph = [[] for _ in range(com + 1)]

for i in range(pair):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

queue = [1]
visited = []

while queue:
    node = queue.pop(0)
    if node not in visited:
        visited.append(node)
    for neighbor in sorted(graph[node]):
        if neighbor not in visited:
            queue.append(neighbor)

print(len(visited)-1)
