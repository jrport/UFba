class leaf:
    def __init__(self,num):
        self.val = None
        self.esq = None
        self.dir = None

class btree:
    def __init__(self):
        self.raiz = None
    
    def insert(self,n):
        n = leaf(n)
        if self.raiz == None:
            self.raiz = n
        else:
            if n.val > self.raiz:
                if self.raiz.esq: 
                    self.insert(self.raiz.esq)
                else: self.raiz.esq = n
            elif n.val < self.raiz:
                if self.raiz.dir:
                    self.insert(self.raiz.dir)
                else: self.raiz.dir = n

    def emordem(self):
        self.temp = self.raiz
        if self.raiz is None:
            print("Árvore Vazia")
        else: 
            if self.temp.esq:
                self.emordem(self.temp.esq)
            print(self.n.val)
            if self.temp.dir:
                self.emordem(self.temp.dir)
                
    def preordem(self):
        if self.temp is None:
            self.temp = self.raiz
        if self.raiz is None:
            print("Árvore Vazia")
        else: 
            print(self.temp.val)
            if self.temp.esq:                
                self.emordem(self.temp.esq)
            if self.temp.dir:
                self.emordem(self.temp.dir)

    def posordem(self):
        if self.temp is None:
            self.temp = self.raiz
        if self.raiz is None:
            print("Árvore Vazia")
        else: 
            if self.temp.esq:
                self.emordem(self.temp.esq)
            if self.temp.dir:
                self.emordem(self.temp.dir)        
            print(self.n.val)

    def find(self,n,begin):
        if n == self.raiz.val or begin is None: return begin
        else:
            if n > self.raiz.val:
                self.find(n,begin.dir)
            else:
                self.find(n,begin.esq)

    def remove(self,n,begin):
        if n < begin.value:
            begin.esq = self.remove(n,begin.esq)
        elif n > begin.value:
            begin.dir = self.remove(n,begin.dir)
        else:
            if (begin.esq is None)&(begin.dir is None):
                return None
            elif (begin.esq is None):
                return begin.dir
            elif (begin.dir is None):
                return begin.esq
            else:
                self.antec = begin.esq
                while self.antec.dir is not None:
                    self.antec = self.maior.dir
                begin.val = self.antec.val
                begin.left = self.remove(self.antec.val,begin.left)
        return begin
    
    

                
