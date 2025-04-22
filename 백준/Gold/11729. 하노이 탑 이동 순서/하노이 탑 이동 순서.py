# 재귀

n = int(input())

def hanoi(n, start, mid, to):
    if (n == 1):
        print (start, to)
        return
    
    hanoi(n-1, start, to, mid)
    print(start, to)
    hanoi(n-1, mid, start, to)

print(2**n - 1)
hanoi(n, 1, 2, 3)