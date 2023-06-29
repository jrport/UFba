class node():
  def __init__(self,num):
    self.val = num
    self.next = None
    self.prev = None

class linked_list():
  def __init__(self):
    self.head = None
  def append(self,num):
    if self.head is None: 
      self.head = node(num)
      return
    cur = self.head
    while cur.next:
      cur = cur.next
    cur.next = node(num)
    cur.next.prev = cur
  def display(self):
    if self.head is None:
      print("Empty list")
      return
    cur = self.head
    while cur:
      print(cur.val,end=" ")
      cur = cur.next
  def swap(self,node,node1):
    node.val, node1.val = node1.val, node.val
  def insert_sort(self,j):
    cur = self.head
    i = 1
    while cur.next and i<j:
      if cur.val>cur.next.val:
        self.swap(cur,cur.next)
      iter = cur.next
      marker = iter
      while iter != self.head:
        if iter.val < iter.prev.val:
          self.swap(iter,iter.prev)
        iter = iter.prev
      cur = cur.next
      i += 1
    show = self.head
    while show!=marker:
      print(show.val,end=' ')
      show = show.next
    print(show.val)

def main():
  lista = linked_list()
  num = int(input())
  times = int(input())
  for i in range(num-1):
    lista.append(int(input()))
  lista.insert_sort(times)

if __name__ == "__main__":
  main()
