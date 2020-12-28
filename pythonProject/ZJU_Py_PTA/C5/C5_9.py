n = int(input())
matrix = [list(map(int, input().split())) for i in range(n)]
row_max_pos = []
col_min_pos = []

for i in range(n):
    mx = max(matrix[i])
    mn = min(int(matrix[j][i]) for j in range(n))
    row_max_pos += [(i, j) for j in range(n) if matrix[i][j] == mx]
    col_min_pos += [(j, i) for j in range(n) if matrix[j][i] == mn]
s = list(set(row_max_pos) & set(col_min_pos))
print(len(s))