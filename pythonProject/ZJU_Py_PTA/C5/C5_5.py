s = input()
ch = input()
d = {}
for c in s:
    if c not in d:
        d[c] = 1
    else:
        d[c] += 1
if ch in s:
    print(d[ch])
else:
    print(0)