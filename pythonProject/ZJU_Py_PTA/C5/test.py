n=int(input())
ls=[list(map(int, input().split())) for i in range(n)]
row_p=[]
col_p=[]
for i in range(n):
    max_row=max(int(ls[i][j]) for j in range(n))
    min_col=min(int(ls[j][i]) for j in range(n))
    row_p+=[(i, j) for j in range(n) if ls[i][j]==max_row]
    col_p+=[(j, i) for j in range(n) if ls[j][i]==min_col]
c=list(set(row_p)&set(col_p))
print(c)
print(len(c))