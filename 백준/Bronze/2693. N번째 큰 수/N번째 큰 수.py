# 삽입정렬

def swap(li, a, b):
    temp = li[b]
    li[b] = li[a]
    li[a] = temp

def insert_sort(A):
    for i in range(len(A)-1):
        if(A[i] > A[i+1]):
            j = 0
            while(j <= i):
                if(A[i + 1] < A[j]):
                    A.insert(j, A[i+1])
                    del A[i+2]
                j += 1
    return A

T = int(input())
result=[]
for i in range(T):
    num = list(map(int, input().split()))
    result.append(insert_sort(num)[7])
for j in range(len(result)):
    print(result[j])