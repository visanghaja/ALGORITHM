# # 계수정렬
# # 저장하지 말고 바로 출력!

# import sys

# n = int(sys.stdin.readline())
# a = [int(sys.stdin.readline()) for _ in range(n)]
# b = [0] * (10001)  # 문제에서 수의 범위는 1~10000

# for i in a:
#     b[i] += 1

# for i in range(1, 10001):
#     if b[i]:
#         for _ in range(b[i]):
#             print(i)

import sys

input = sys.stdin.readline
count = [0] * 10001  # 수의 범위는 1~10000

n = int(input())
for _ in range(n):
    count[int(input())] += 1

for i in range(1, 10001):
    for _ in range(count[i]):
        print(i)
