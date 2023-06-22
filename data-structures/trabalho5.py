class tree_node():
  def __init__(self,int):
    self.value = int
    self.right = None
    self.left = None

class btree():  
  def __init__(self):
    self.root = None
    self.check = False
  def add(self, num, base): 
    if self.root is None: self.root = tree_node(num)
    else:
      if base.value > num:
        if base.left is None: base.left = tree_node(num)
        else:
          self.add(num,base.left)
      else:
        if base.right is None: base.right = tree_node(num)
        else:
          self.add(num,base.right)
  def InOrder(self,node):
    if node is None: return
    self.InOrder(node.left)
    print(node.value)
    self.InOrder(node.right)
  def find(self,num,base):
    if base.value == num:
      return base
    else:
      if base.value>num: 
        return self.find(num,base.left)
      else:
        return self.find(num,base.right)
  def find_p(self,num,base):
    if base.value>num:
      if base.left.value == num: 
        return base
      else: return self.find_p(num,base.left)
    else:
      if base.right.value == num: return base
      else: return self.find_p(num,base.right)
  def find_pred(self,num,base):
    start = self.find(num,self.root)
    start = start.left
    while start.right is not None:
      start = start.right
    return start
  def remove_root(self):
    pred = self.find_pred(self.root.value,self.root)
    pred.right = self.root.right
    pred_p = self.find_p(pred.value,self.root)
    if pred != self.root.left:
      if pred.left is not None:
        pred_p.right = pred.left
      else:
        pred_p.right = None
      pred.left = self.root.left
    self.root.right = None
    self.root.lef = None
    self.root = pred
  def remove(self,num):
    adr = self.find(num,self.root)
    if adr == self.root:
      self.remove_root()
    else:
      p_num = self.find_p(num,self.root)
      if (adr.right is  None)and(adr.left is  None):
        if p_num.right == adr: p_num.right = None
        else: p_num.left = None
      elif (adr.right is  None)or(adr.left is  None):
        if p_num.right == adr: 
          if adr.right is not None: 
            p_num.right = adr.right
            adr.right = None
          else:
            p_num.right = adr.left
            adr.left = None
        else:
          if adr.right is not None: 
            p_num.left = adr.right
            adr.right = None
          else:
            p_num.left = adr.left
            adr.left = None 
      else:
        pred = self.find_pred(adr.value,self.root)
        pred.right = adr.right
        pred_p = self.find_p(pred.value,self.root)
        if pred_p != adr:
          if pred.left is None:
            pred.left = adr.left
          else:
            pred_p.right = pred.left
            pred.left = adr.left
          adr.right = None
          adr.left = None
          if p_num.right == adr:
            p_num.right = pred
          else: 
            p_num.left = pred
        else:
          pred.right = adr.right
          if pred.left is None:
            pred.left = adr.left
          adr.left = None
          adr.right = None
          if p_num.right == adr:
            p_num.right = pred
          else: 
            p_num.left = pred
  def InOrderStop(self,target,node):
    self.InOrderStopRecursive(target,node)
  def InOrderStopRecursive(self,target,node):
    if self.check == False:
      if node is None: return
      self.InOrderStop(target,node.left)
      if self.check == False:
        print(node.value, end=' ')
      if node.value != target:
        self.InOrderStop(target,node.right)
      else: self.check = True

def main():
  a = int(input())
  tree = btree()
  vector = [int(i) for i in input().split()]
  for i in vector:
    tree.add(i,tree.root)
  rem = [int(i) for i in input().split()]
  target = int(input())
  tree.InOrderStop(target,tree.root)
  tree.check = False
  print("\n",end="")
  for i in rem:
    tree.remove(i)
  tree.InOrderStop(target,tree.root)

if __name__ == '__main__':
  main()