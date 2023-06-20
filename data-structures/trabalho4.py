class treenode():
    def __init__(self, num):
        self.id = num
        self.left = None
        self.right = None

class qnode():
    def __init__(self, num):
        self.adress = num
        self.prev = None

class queue():
    def __init__(self):
        self.top = None
    def add(self,num):
        if self.top is None: self.top = qnode(num)
        else:
            cur = self.top
            while cur.prev is not None:
                cur = cur.prev
            cur.prev = qnode(num)
    def pop(self):
        pholder = self.top
        self.top = self.top.prev
        return pholder

class NewTree():
    def __init__(self):
        self.root = None
    def ClearTree(self):
        self.root = None
    def InOrder(self,node):
        if node is not None: 
            self.InOrder(node.left)
            print(node.id)
            self.InOrder(node.right)
    def Depht(self):
        cur = self.root
        d = 0
        while cur.left is not None:
            cur = cur.left
            d += 1
        return d
    def Add(self,itens):
        self.root = treenode(itens[0])
        order = queue()
        order.add(self.root)
        n = 1
        while n < len(itens):
            focus = order.pop()
            if itens[n] is not None:
                focus.adress.left = treenode(itens[n])
                order.add(focus.adress.left)
            n += 1
            if n > (len(itens)-1): break
            if itens[n] is not None:
                focus.adress.right = treenode(itens[n])
                order.add(focus.adress.right)
            n += 1
    def Search(self, root, num, depht = 0):
        if root is None: return -1
        elif root.id == num: return depht
        dleft_tree = self.Search(root.left, num, depht+1)
        if dleft_tree != -1: return dleft_tree
        dright_tree = self.Search(root.right, num, depht+1)
        return dright_tree
    def Find(self,root,node):
        if root is None: return None
        if root.id == node: return root 
        lefts = self.Find(root.left,node)
        if lefts is not None: return lefts
        rights = self.Find(root.right,node)
        if rights is not None: return rights   
        return None     
    def Height(self, node):
        height = 0
        root = self.Find(self.root,node)
        if root.left is None: return 0
        else: 
            while root.left is not None:
                root = root.left
                height += 1
            return height

def main():
    size = int(input())
    vector = [int(i) for i in input().split()]
    tree = NewTree()
    tree.Add(vector)
    pairs = []
    for i in range(size-1):
        pair = [int(i) for i in input().split()]
        pairs.append(pair)
    for i in pairs:
        dfirst = tree.Search(tree.root,i[0])
        dsecond = tree.Search(tree.root,i[1])
        if (dfirst == -1)and(dsecond == -1):
            print(tree.Depht())
        elif (dfirst == -1) or (dsecond == -1):
            if dfirst > -1: print(tree.Height(i[0]))
            else: print(tree.Height(i[1]))
        else:
            print(max(dfirst,dsecond)-min(dfirst,dsecond))
if __name__ == "__main__":
    main()
