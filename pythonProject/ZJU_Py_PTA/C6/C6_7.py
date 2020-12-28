n = int(input())
stu_list = []
for i in range(n):
    scores = []
    stu_info = {}
    sum = 0
    l = list(map(str, input().split()))
    stu_info['id'] = l[0]
    stu_info['name'] = l[1]
    for k in range(2, 5):
        score = int(l[k])
        scores.append(score)
        sum += score
    stu_info['scores'] = scores
    stu_info['sum'] = sum
    stu_list.append(stu_info)
stu_list.sort(key=lambda x: x['sum'], reverse=True)
sum_max = list(stu_list[0].values())
print(sum_max[1] + ' ' + sum_max[0] + ' ' + str(sum_max[-1]))