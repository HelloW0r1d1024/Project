from math import pi
class Circle:

    def __init__(self, r):
        self.r = r
        self.circum = self.CalcCir(r)
        self.area = self.CalcArea(r)
    
    def CalcCir(self, r):
        return 2 * pi * r
    def CalcArea(self, r):
        return pi * r**2

for i in range(1, 101):
    print("半径:%d, 周长%.2f, 面积%.2f" % (i, Circle(i).circum, Circle(i).area))

