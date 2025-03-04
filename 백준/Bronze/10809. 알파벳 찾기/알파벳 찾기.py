S = input()
alpa = {}

for i in ("abcdefghijklmnopqrstuvwxyz"):
    alpa[i] = -1

z = 0
for j in S:
    if (j in alpa and alpa[j] == -1):
        alpa[j] = z
    z += 1
for s in ("abcdefghijklmnopqrstuvwxyz"):
    print(alpa[s], end = " ")