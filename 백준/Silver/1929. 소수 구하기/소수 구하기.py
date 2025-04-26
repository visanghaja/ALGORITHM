# math
# 소수인지 알아보는 법 : 2 이상의 수라면 그 수의 제곱근까지 나눠보기 (나누어떨어지는 수가 하나라도 있으면 소수 X)

import sys

m, n = map(int, sys.stdin.readline().split())

for i in range(m, n+1):
    if i == 1:
        continue
    
    for j in range(2, int(i**0.5)+1):
        if i%j == 0:
            break
    
    else:
        print(i)
