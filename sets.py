class MySet:
    def _init_(self):
        self.items = []

    def add(self, item):
        if item not in self.items:
            self.items.append(item)

    def remove(self, item):
        if item in self.items:
            self.items.remove(item)

    def contains(self, item):
        return item in self.items

    def size(self):
        return len(self.items)

    def union(self, other_set):
        new_set = MySet()
        new_set.items = self.items.copy()
        for item in other_set.items:
            new_set.add(item)
        return new_set

    def intersection(self, other_set):
        new_set = MySet()
        for item in self.items:
            if other_set.contains(item):
                new_set.add(item)
        return new_set

    def difference(self, other_set):
        new_set = MySet()
        for item in self.items:
            if not other_set.contains(item):
                new_set.add(item)
        return new_set

    def is_subset(self, other_set):
        for item in self.items:
            if not other_set.contains(item):
                return False
        return True

    def display(self):
        print(self.items)


# Example usage:
set1 = MySet()
set1.add(1)
set1.add(2)
set1.add(3)
set1.display()  # Output: [1, 2, 3]

set2 = MySet()
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