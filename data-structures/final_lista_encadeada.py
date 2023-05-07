class node:
    def __init__(self,valor):
        self.valor = valor
        self.prox = None
class New_List:
    def __init__(self):
        self.head = None
    def append(self,valor):
        valor = node(valor)
        if self.head is None: self.head = valor
        else: 
            current_node = self.head
            while current_node.prox is not None:
                current_node = current_node.prox
            current_node.prox = valor
    def display(self):
        if self.head is None: print("Lista Vazia!")
        else:
            print("--------- Lista Encadeada: ---------")
            current_node = self.head
            while current_node.prox is not None:
                print(current_node.valor, end=' -> ')
                current_node = current_node.prox
            print(current_node.valor,end=' -> ')
            print("None \n----------- Fim da Lista -----------")
    def insert(self,indice,valor):
        valor = node(valor)
        current_node = self.head
        for i in range(indice-1):
            current_node = current_node.prox
        valor.prox = current_node.prox
        current_node.prox = valor
    def free(self):
        self.head = None
    def insert_lista(self,indice,enxerto):
        current_node = self.head
        for i in range(n-1):
            current_node = current_node.prox
        enxerto_node = enxerto.head
        for i in range(i- 1):
            enxerto_node = enxerto_node.prox
        enxerto_node.prox = current_node.prox
        current_node.prox = enxerto.head
    def no_repeat(self):
        unique_nodes = set()
        current_node = self.head
        no_repeat_list = New_List()
        while current_node.prox is not None:
            if current_node.valor not in unique_nodes:
                unique_nodes.add(current_node.valor)
                no_repeat_list.append(current_node.valor)
                current_node = current_node.prox
            else: current_node = current_node.prox
        self.free()
        self.head = no_repeat_list.head

lista = New_List()
lista.append("caderno")
lista.append("borracha")
lista.append("lapiseira")
lista.append("caneta")
lista.append("lapiseira")
lista.append("borracha")
lista.display()
lista.no_repeat()
lista.display()