# 선택정렬

N = int(input())
num = []
for i in range(N):
    A = int(input())
    num.append(A)

na = len(num)

while(na > 0):
    max = 0
    for j in range(na):
        if(num[max] <= num[j]):
            max = j
    temp = num[na-1]
    num[na-1] = num[max]
    num[max] = temp
    na -= 1

for z in range(len(num)):
    print(num[z])