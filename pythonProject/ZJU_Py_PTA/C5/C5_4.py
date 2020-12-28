s = list(map(int, input().split(',')))
print(*[i for i in range(6, 11) if i not in s], sep=' ')

'''
d = {6:False, 7:False, 8:False, 9:False, 10:False}
for j in set(int(i) for i in s):
    if 6 <= j <= 10:
        d[j] = True
for key in d:
    if d[key] == False:
        print(' {:d}'.format(key),end="")
'''