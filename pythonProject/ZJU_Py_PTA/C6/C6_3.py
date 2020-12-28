def f(l):
    s = 0
    if isinstance(l, int):
        s += l
    if isinstance(l, list) or isinstance(l, tuple):
        for i in l:
            s += f(i)
    return s

l = eval(input())
print(f(l))