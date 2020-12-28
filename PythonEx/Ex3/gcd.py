def gcd(a, b):
    if a % b != 0:
        return gcd(b, a % b)
    else:
        return b
        
def lcm(a, b):
    return a * b // gcd(a, b)

a, b = map(int, input().split())
print(gcd(a, b))
print(lcm(a, b))