class Myset:
    def __init__(self):
        self.items = []

    def add(self,key):
        if key not in self.items:
            self.items.append(key)

    def remove(self, key):
        if key in self.items:
            self.items.remove(key)
    
    def contains(self, key):
        return key in self.items
    
    def size(self):
        return len(self.items)
    
    def union(self, set2):
        set1 = Myset()
        set1.items = self.items.copy()
        for item in set2.items:
            set1.add(item)
        return set1

    def intersection(self, set2):
        set1 = Myset()
        for item in self.items:
            if set2.contains(item):
                set1.add(item)
        return set1
    
    def difference(self, set2):
        set1 = Myset()
        for item in self.items:
            if not  set2.contains(item):
                set1.add(item)
        return set1
    
    def is_subset(self,set2):
        for item in self.items:
            if not set2.contains(item):
                return False
        return True
    def display(self):
        print(self.items)



set1 = Myset()
set1.add(1)
set1.add(2)
set1.add(3)
set1.display() 

set2 = Myset()
set2.add(2)
set2.add(3)
set2.add(4)
union_set = set1.union(set2)
union_set.display()  # Output: [1, 2, 3, 4]

intersection_set = set1.intersection(set2)
intersection_set.display()  # Output: [2, 3]

difference_set = set1.difference(set2)
difference_set.display()  # Output: [1]

print(set1.is_subset(set2))  