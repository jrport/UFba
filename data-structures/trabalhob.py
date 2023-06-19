class plate():
    def __init__(self, n):
        self.valor = n
        self.baixo = None

class stack():
    def __init__(self):
        self.topo = None
    def push_back(self,n):
        if self.topo:
            new_plate = plate(n)
            new_plate.baixo = self.topo
            self.topo = new_plate
        else:
            new_plate = plate(n)
            self.topo = new_plate      
    def pop(self):
        if self.topo.baixo: self.topo = self.topo.baixo
        else: self.topo = None
    def vazia(self):
        if self.topo is None: return True
        else: return False
    def display(self):
        cur = self.topo
        print(cur)
        while cur is not None:
            print(cur.valor)
            cur = cur.baixo

def main():
    conta = input()
    limites = ['[',']','{','}','(',')']
    abre = ['[','(','{']
    fecha = [']',')','}']
    parenteses = []
    for i in conta:
        if i in limites: parenteses.append(i)
    pilha = stack()
    for i in parenteses:
          if pilha.topo is None:
              pilha.push_back(i)
          else: 
              if i not in abre:
                  if pilha.topo.valor == '(': 
                    if i == ')': pilha.pop()
                  elif pilha.topo.valor == '{':
                    if i == '}': pilha.pop()
                  elif pilha.topo.valor == '[':
                    if i == ']': pilha.pop()
              else: pilha.push_back(i)
    if pilha.vazia(): print("Valido")
    else: print("Invalido")
    


            
    

    

if __name__ == '__main__':
    main()