import sys
s = sys.stdin.read()    
s = s[:s.find('#')]     # 使用切片去掉字符串末的'＃'
# 将字符串中非字母、数字、下划线的字符挑出来， 全部替换为' '
for k in set(i for i in s if not i.isalnum() and i != '_'):
    s = s.replace(k, ' ')
l = s.lower().split()   # 全转小写并将每个单词放到列表里
d = {}
# key为单词 val为出现次数
for i in l:
    if len(i) > 15: # 长度超过15，截取保留
        i = i[:15]
    if i not in d:
        d[i] = 1
    else:
        d[i] += 1
# item()返回字典的(key，value)元组对的列表，并按频数排序，若有并列，则按递增字典序输出
d = sorted(d.items(), key = lambda x:(-x[1], x[0]))
print(len(d)) # 总单词数

for i in d[:len(d) // 10]: # 输出前10%
    print(i[1], i[0], sep = ':')