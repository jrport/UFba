class node():
    def __init__(self):
        self.id = None
        self.valor = None
        self.atras = None

class queue():
    def __init__(self):
        self.head = None
        self.up = None
        self.max = None
    def push_back(self,n):
        if self.head:
            cur = self.head
            while cur.atras:
                cur = cur.atras
            cur.atras = n
        else: self.head = n
    def pop(self):
        self.head = self.head.atras
    def go_back(self):
        if self.head.atras:
            new = self.head
            cur = self.head
            self.head = cur.atras
            while cur.atras:
                cur = cur.atras
            cur.atras = new
            new.atras = None
    def roundr(self):
        cur = self.head
        while self.max:
            if self.max>self.up:
                if self.head.valor>self.up: 
                    self.head.valor = self.head.valor - self.up
                    self.max = self.max - self.up
                    self.go_back()
                elif self.head.valor==self.up:
                    self.max = self.max - self.up
                    self.pop()
                else:
                    self.max = self.max - (self.head.valor)
                    self.pop()
            else:
                self.head.valor -= self.max
                self.go_back()
                self.max = 0
        self.htop()
    def htop(self):
        cur = self.head
        ids = ''+str(cur.id)
        ups = ''+str(cur.valor)
        while cur.atras:
            cur = cur.atras
            ids += ' ' + str(cur.id)
            ups += ' ' + str(cur.valor)
        print(ids)
        print(ups)
            
        
def main():
    a = input()
    fila = queue()
    fila.up, fila.max = [int(i) for i in input().split()]
    ids = [int(i) for i in input().split()]
    values = [int(i) for i in input().split()]
    for i in range(len(ids)):
        new_el = node()
        new_el.id = ids[i]
        new_el.valor = values[i]
        fila.push_back(new_el)
    fila.roundr()

if __name__ == '__main__':
    main()