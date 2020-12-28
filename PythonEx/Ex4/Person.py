class Person:
    def __init__(self, id, name):
        self.id = id
        self.name = name
    
    def display(self):
        print("编号:%s, 姓名:%s" % (self.id, self.name), end="")

class Student(Person):
    def __init__(self, id, name, cls, score):
        super().__init__(id, name)
        self.cls = cls
        self.score = score
    
    def display(self):
        super().display()
        print(", 班号:%s, 成绩:%d" % (self.cls, self.score))

class Teacher(Person):
    def __init__(self, id, name, title, dpt):
        super().__init__(id, name)
        self.title = title
        self.dpt = dpt
    
    def display(self):
        super().display()
        print(", 职称:%s, 部门:%s" % (self.title, self.dpt))

s1 = Student("12345", "张三", "1921", 500)
t1 = Teacher("67891", "李四", "教授", "数学系")
s1.display()
t1.display()