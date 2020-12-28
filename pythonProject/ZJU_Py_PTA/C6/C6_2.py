N = int(input())
s = [input().split() for i in range(N)]
print(s)
while len(s):
    i = 0 # 始终指向第一个学生
    j = -1 # 指向i对称位置的学生   
    while s[i][0] == s[j][0]:
        j -= 1  # 同性则向前找

    print(s[i][1] + ' ' + s[j][1])
    del s[i], s[j]




'''
N = int(input())
s = [input().split() for i in range(N)]
l = []
for i in s:
    t = []
    t.append(i[0])
    t.append(i[1])
    l.append(t)

l = []
while len(l):
    i = 0
    a = []
    a.append(l[i][1])
    j = -(i + 1)
    while l[i][0] == l[j][0]:
        j -= 1
    a.append(l[j][1])
    l.pop(i)
    l.pop(j)
    l.append(a)

for i in l:
    print(i[0] + ' ' + i[1])
'''# i  -(i + 1)