d1 = eval(input())
d2 = eval(input())
for i in d2:
    if i in d1:
        d1[i] += d2[i]
    else:
        d1[i] = d2[i]
d1 = str(dict(sorted(d1.items(), key=lambda x: x[0] if isinstance(x[0], int) else ord(x[0]))))
d1 = d1.replace(' ', '')
d1 = d1.replace("'", '"')
print(d1)