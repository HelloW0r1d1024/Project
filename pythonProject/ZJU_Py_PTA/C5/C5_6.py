N = int(input())
l = list(map(int, input().split()))
d = {}
for i in l:
    if i not in d:
        d[i] = 1
    else:
        d[i] += 1
d = sorted(d.items(), key= lambda x:x[0])
for i in d:
    print(str(i[0]) + ':' + str(i[1]))