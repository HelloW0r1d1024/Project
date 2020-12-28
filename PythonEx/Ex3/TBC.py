def MaxMinCnt(s):
    return (max(s), min(s), len(s))
s = eval(input())
t = MaxMinCnt(s)
print("最大值=" + str(t[0]) + "，最小值=" + str(t[1]) + "，元素个数=" + str(t[2]))