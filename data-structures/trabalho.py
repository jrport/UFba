class node():
    def __init__(self, n):
        n = int(n)
        self.value = n
        self.next = None
class linked_list():
    def __init__(self):
        self.head = None
        self.cycle = False
    def append(self,n):
        new_el = node(n)
        if self.head == None:
            self.head = new_el
        else:
            temp = self.head
            while temp.next!=None:
                temp = temp.next
            temp.next = new_el
    def check_cycle(self):
        fast = self.head
        slow = self.head
        while (slow and fast and fast.next):
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                self.cycle = True
                return True
        return False
    def find(self,n):
        temp = self.head
        while temp.value!=int(n):
            temp = temp.next
        return temp
    def link(self,a,b):
        temp1 = self.find(a)
        temp2 = self.find(b)
        temp1.next = temp2
        self.check_cycle()

def main():
    size = int(input())
    nodes = [int(i) for i in input().split()]
    ll = linked_list()
    pairlist = []
    for i in nodes:
        ll.append(i)
    for i in range(size-1):
        pair = [int(i) for i in input().split()]
        pairlist.append(pair)
    for duo in pairlist:
        ll.link(duo[0],duo[1])
    if ll.cycle: print("Ciclo")
    else: print("Sem Ciclo")

if __name__=='__main__':
    main()

