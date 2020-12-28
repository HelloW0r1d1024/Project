class Vehicle:
    def __init__(self, wheels, weight):
        self.wheels = wheels
        self.weight = weight

    def setWheels(self, wheels):
        self.wheels = wheels

    def getWheels(self):
        return self.wheels

    def setWeight(self, weight):
        self.wheels = wheels

    def getWeight(self):
        return self.weight

    def display(self):
        print("车轮:%d, 重量:%d" % (self.getWheels(), self.getWeight()), end="")

class Car(Vehicle):

    def __init__(self, wheels, weight, passenger_load):
        super().__init__(wheels, weight)
        self.passenger_load = passenger_load

    def setPassenger_load(self, passenger_load):
        self.passenger_load = passenger_load
    
    def getPassenger_load(self):
        return self.passenger_load
    
    def display(self):
        super().display()
        print(", 载客量:%d" % self.getPassenger_load(),end="")

class Truck(Car):
    def __init__(self, wheels, weight, passenger_load, payload):
        super().__init__(wheels, weight, passenger_load)
        self.payload = payload
    
    def setPayload(self, payload):
        self.payload = payload
        
    def getPayload(self):
        return self.payload
    
    def display(self):
        super().display()
        print(", 载客量:%d, 载重量:%d" % (self.getPassenger_load(), self.getPayload())),

v1 = Vehicle(4, 100)
c1 = Car(5, 200, 5)
t1 = Truck(6, 300, 2, 150)
v1.display()
print()
c1.display()
print()
t1.display()
