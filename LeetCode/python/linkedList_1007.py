class Node(object):

    def __init__(self, initdata):
        self.data = initdata
        self.next = None #引用的node没有下一个节点

    def getData(self):
        return self.data

    def getNext(self):
        return self.next

    def setData(self, newData):
        self.data = newData
    
    def setNext(self, newNext):
        self.next = newNext

class unOrderList():

    def __init__(self):
        self.head = None
    
    def isEmpty(self):
        return self.head == None
    
    def add(self, item):
        temp = Node(item)
        temp.setNext(self.head)
        self.head = temp
    
    def size(self):
        current = self.head
        count = 0
        while current != None:
            count +=1
            current = current.getNext()
        return count

    def remove(self, item):
        current = self.head
        previous = None
        found = False
        while not found:
            if current.getData() == item:
                found = True
            else:
                previous = current
                current = current.getNext()

        if previous == None:
            self.head = current.getNext()
        else:
            previous.setNext(current.getNext())
    
    def traversal(self):
        current = self.head
        while current != None:
            print(current.getData())
            current = current.getNext()


# tmp = Node(33)
# print("tmp",tmp, "data", tmp.getData())

myList = unOrderList()
myList.add(31)
myList.add(77)
myList.add(17)
myList.add(93)
myList.add(26)
# print("myList size:", myList.size())
myList.traversal()
myList.remove(17)
myList.traversal()

    