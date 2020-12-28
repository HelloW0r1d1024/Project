def f(l, deep):
    s = 0

    if isinstance(l, int):
        s += l * deep
    if isinstance(l, list):
        deep += 1
        for i in l:
            s += f(i, deep)
    return s

l = eval(input())
print(f(l, 0))
