def is_prime(x):
    for i in range(2, int(x**0.5)+1):
        if x % i == 0:
            return False
    return True and x != 1 and x != 0

sum = 0
for i in range(1000):
    if is_prime(i):
        print(i)
        sum += i
print("这些素数的和为：%d" % sum)