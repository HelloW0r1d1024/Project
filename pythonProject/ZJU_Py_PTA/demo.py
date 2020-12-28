a = [115.5,115.6,115.3,115.2,115.3,115.4]
avgA = sum(a) / len(a)
xA = 0
for i in a:
    xA += (i - avgA) ** 2
UAa = (1.11/6**0.5) * ((1/5) * xA) ** 0.5
UBa = 0.25/3
Ua = (UAa**2 + UBa**2)**0.5


b = [20.02,20.12,20.08,20.02,20.00,20.10]
avgB = sum(b) / len(b)
xB = 0
for i in b:
    xB += (i - avgB) ** 2
UAb = 1.11 * (xB/30)**0.5
UBb = 0.02/(3)**0.5
Ub = (UAb**2 + UBb**2)**0.5


d = [4.980,4.968,4.972,4.979,4.995,4.969]
avgD = sum(d) / len(d)
xD = 0
for i in d:
    xD += (i - avgD) ** 2
UAd = 1.11 * (xD/30)**0.5
UBd = 0.004 / 3
Ud = (UAd**2 + UBd**2)**0.5

print("%.3f %.3f %.3f" % (UAa, UBa, Ua))
print("%.3f %.3f %.3f" % (UAb, UBb, Ub))
print("%.3f %.3f %.3f" % (UAd, UBd, Ud))