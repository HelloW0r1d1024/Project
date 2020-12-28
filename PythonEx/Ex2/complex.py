r, i = map(int, input().split())
print(str(r) + ' + ' + str(i) + 'i')
print("这个复数的模为%d" % (r**2 + i**2)**0.5)