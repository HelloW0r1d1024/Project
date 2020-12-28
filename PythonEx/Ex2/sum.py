def sum(num):
    s = 0
    for i in range(1, num+1):
        s += i**2
    return s

s = 0
i = 1

print("n\ts")
while s < 1000:
    s = sum(i)
    if s < 1000:
        print("%d\t%d" % (i, s))
        i += 1
print("累计和不超过1000的最大项数是%d" % (i-1))