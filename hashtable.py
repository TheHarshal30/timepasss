class HashTable:
    def __init__(self):
        self.MAX = 10
        self.arr = [[] for i in range(self.MAX)]

    def get_hash(self, key):
        hash = 0
        for char in key:
            hash += ord(char)
        return hash % self.MAX

    def __getitem__(self,key):
        arr_index = self.get_hash(key)
        print(len(self.arr[arr_index]))
        list = []
        for ans in self.arr[arr_index]:
            if ans[0] == key:
                list.append(ans[1])
        return list

    def __setitem__(self,key, val):
        h = self.get_hash(key)
        found = False
        for idx,element in enumerate(self.arr[h]):
            if element[0] == key:
                self.arr[h].append((key, val)) 
                found = True
                break
        if not found:
            self.arr[h].append((key,val))

    def __delitem__(self, key):
        h = self.get_hash(key)
        for idx, element in enumerate(self.arr[h]):
            if element[0] == key:
                print("delete", key)
                del self.arr[h][idx]
    



table = HashTable()
table["harsh"] = 123456
table["tesla"] = 45678
table["tesla"] = 4567899

print(table["tesla"])