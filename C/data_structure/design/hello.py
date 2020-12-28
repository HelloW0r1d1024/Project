import random

def id_indentify():
    str = input()
    if len(str) != 6:
        return False
    else:
        flag = True
        for i in range(6):
            if i < 2:
                if str[i] < 'A' or str[i] > 'Z':
                    flag = False
            else: #48 57
                if str[i] < '0' or str[i] >'9':
                    flag = False
    return flag

def list_factor(num, factor):
    tmp = int(num ** 0.5)
    cnt = 0

    for i in range(2, int(tmp + 1)):
        if num % i == 0:
            factor.append(i)
            cnt += 1
            if i != num // i:
                factor.append(num / i)
    if 0 == cnt:
        return False
    else:
        return True

def op_generator(opList):
    op_index = 0
    flag = [False, False, False, False]
    
    while (not(flag[0] and flag[1] and flag[2] and flag[3])):
        opList.append(random.randint(0, 3))
        for i in range(1, 10):
            while True:
                op_index = random.randint(0, 3)
                if op_index != opList[i - 1]:
                    break
            
            if 0 == op_index:
                flag[0] = True
            elif 1 == op_index:
                flag[1] = True
            elif 2 == op_index:
                flag[2] = True
            elif 3 == op_index:
                flag[3] = True
            opList.append(op_index)

op = ['+', '-', '*', '/']
opList = []
op_generator(opList)
for i in range(10):
    print(op[opList[i]])

