# 버블정렬

def swap(li, a, b):
    temp = li[b]
    li[b] = li[a]
    li[a] = temp

N, k = map(int, input().split())
score = list(map(int, input().split()))
i = len(score)

while(i > 0):
    max = score[0]
    for j in range(i):
        if(j + 1 != len(score)):
            if(score[j] > score[j+1]):
                swap(score, j, j+1)
    i -= 1

print(score[len(score) - k])