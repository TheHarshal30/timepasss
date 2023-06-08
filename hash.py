class HashTable:
    def __init__(self):
        self.Max = 10
        self.arr = [[] for i in range(self.Max)]

    def getHash(self,key):
        hash = 0
        for char in key:
            hash += ord(char)
        return hash % self.Max
    
    def __getitem__(self,key):
        h = self.getHash(key)
        list = []
        for ans in (self.arr[h]):
            if ans[0] == key:
                list.append(ans[1])
        return list
    
    def __setitem__(self,key,val):
        h = self.getHash(key)
        found = False
        for idx, element in enumerate(self.arr[h]):
            if element[0] == key:
                if (self.arr[h]) is not None:
                    h = (h+1)%self.Max
                self.arr[h].append((key,val))
                found = True
                break
        if not found:
            self.arr[h].append((key,val))
    
    def __delitem__(self,key):
        h = self.getHash(key)
        for idx, element in enumerate(self.arr[h]):
            if element[0] == key:
                del self.arr[h][idx]


table = HashTable()
table["harsh"] = 1234545
table["harsh"] = 45667
table["tesla"] = 55555
table["tesla"] = 55556
print(table.arr)