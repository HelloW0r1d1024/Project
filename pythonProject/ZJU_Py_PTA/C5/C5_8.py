'''
l = list(map(int, input().split()))
cnt = 0

for i in range(l[0], l[1]):
    if i % 3 == 0 and i % 5 == 0 and i % 7 == 0:
        cnt += 1
print(cnt)
'''
a,b=map(int,input().split())
print(b//105-a//105)