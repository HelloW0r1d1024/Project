def list_factor(num):
    l = []
    tmp = int(num**0.5)
    
    for i in range(2, tmp + 1):
        if num % i == 0:
            l.append(i)
            if i != num // i:
                l.append(num // i)
    print(l)

x = int(input())
list_factor(x)