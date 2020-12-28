l = eval(input())
s = []
for i in l:
    if i not in s:
        s.append(i)
print(*s)