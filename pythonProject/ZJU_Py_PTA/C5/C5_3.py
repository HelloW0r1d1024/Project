d = {'+':'a+b', '-':'a-b', '*':'a*b', '/':'a/b'}
a = int(input())
op = input()
b = int(input())

if op == '/' and b == 0:
    print('divided by zero')
else: 
    print("%.2f" % eval(d[op]))