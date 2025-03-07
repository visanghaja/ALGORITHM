# 병합정렬
# 그리디 알고리즘
import sys

def mergeSort(A):
    if(len(A) < 2):
        return A
    mid = len(A) // 2 # 결과 자연수 
    low_a = mergeSort(A[:mid])
    high_a = mergeSort(A[mid:])
    merge_arr = []
    i = j = 0

    while i < len(low_a) and j < len(high_a):
        if low_a[i] < high_a[j]:
            merge_arr.append(low_a[i])
            i += 1
        else:
            merge_arr.append(high_a[j])
            j += 1
    merge_arr += low_a[i:]
    merge_arr += high_a[j:]
    
    return merge_arr

def greedy(A):
    sum = 0
    for i in range(len(A)):
        if(A[i] < sum + 2):
            sum += A[i]
        else:
            break
    return sum + 1


N = int(input())

board = list(map(int, sys.stdin.readline().split()))

sorted_arr = mergeSort(board)
print(greedy(sorted_arr))