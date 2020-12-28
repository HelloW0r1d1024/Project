nums = list(map(int, input().split(',')))
n = int(input())
d = {}
for i in nums:
    d[i] = n - i

for key, value in d.items():
    if key in nums and value in nums:
        print(nums.index(key), nums.index(value))
        break
else:
    print("no answer")