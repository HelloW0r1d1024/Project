n = int(input())
num = 0 # 边
sum = 0 # 边的总长度
for i in range(n):
    dic = eval(input())

    for j in dic:   # 将字典的字典赋给tmp
        tmp = dic[j]
        for key in tmp:
            num += 1    # 有几个键就有几条边
            sum += tmp[key]
print("{:d} {:d} {:d}".format(n,num,sum))



'''
def f(d):
    l = []
    sum = 0
    cnt = 0
    for i in d:
        i = list(list(i.values())[0].values())
        for j in i:
            sum += j
        cnt += len(i)
    l.append(cnt)
    l.append(sum)
    return l

n = int(input())
s = [eval(input()) for i in range(n)]
l = f(s)
print(str(n) + ' ' + str(l[0]) + ' ' + str(l[1]))
'''