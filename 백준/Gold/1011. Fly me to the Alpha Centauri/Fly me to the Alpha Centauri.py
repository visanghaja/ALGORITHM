# math

import sys
import math

def dis(x, y):
    count = 0
    distance = y - x
    root = math.floor(math.sqrt(distance)) # floor 는 내림처리!
    root2 = root**2
    
    if (distance <= 3):
        count = distance
    elif (distance == root2):
        count = (root * 2) - 1
    elif (root2 < distance <= root2 + root):
        count = (root * 2)
    elif (root2 + root < distance):
        count = (root * 2) + 1
    
    return count




result = []
T = int(input())
for i in range(T):
    x, y = map(int, sys.stdin.readline().split())
    result.append(dis(x, y))

for j in result:
    print(j)