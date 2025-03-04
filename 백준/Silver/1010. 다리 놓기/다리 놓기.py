def fact(n):
    num = 1
    for i in range(1, n+1):
        num *= i
    return num

numb = int(input())
for _ in range(numb):
    n, m = map(int, input().split())
    print(fact(m) // (fact(n) * fact(m-n)))