n = int(input())
matrix = [input().split() for i in range(n)]
cnt = 0
if max(matrix) == min(matrix):
    cnt = n ** 2
else:
    for row in matrix:
        tag = True
        mx = max(row)
        idx = row.index(mx)
        for i in matrix:
            if mx > i[idx]:
                tag = False
        if tag:
            cnt += 1
print(cnt)
