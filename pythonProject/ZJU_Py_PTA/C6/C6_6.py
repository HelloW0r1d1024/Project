def f(l, deep, num):
    s = 0
    if isinstance(l, int) and deep == num:
        s += 1
    if isinstance(l, list):
        deep += 1
        for i in l:
            s += f(i, deep, num)
    return s


l = eval(input())
num = int(input())
print(f(l, 0, num))