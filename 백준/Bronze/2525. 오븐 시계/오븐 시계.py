H, M = map(int, input().split())
i = int(input())

if (M + i < 60):
    print (H, (M+i))
if (M + i >= 60):
    h = (M+i)//60
    m = (M+i) - (h*60)
    if m == 60:
        m == 0

    if ((H+h) >= 24):
        print (((H+h)-24), (m))
    else:
        print ((H+h), (m))