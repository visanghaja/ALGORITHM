n = int(input())
lst = list(map(int, input().split()))
maxScore = max(lst)
newlst = []

for i in lst:
    newlst.append(i/maxScore*100)
print(sum(newlst)/n)
