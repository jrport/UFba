class node():
  def __init__(self, num):
    self.val = num
    self.next = None
    self.elements = None

class linked_list():
  def __init__(self):
    self.head = None
    self.hash_table = None

  def append(self,num):
    if self.head is None: self.head = node(num)
    else:
      cur = self.head
      while cur.next is not None:
        cur = cur.next
      cur.next = node(num)

  def display(self):
    cur = self.head
    if cur is None: 
      print("Empty")
      return
    while cur:
      print(cur.val, end=' ')
      cur = cur.next
    print('\n',end='')

  def get_ascii_val(self,string):
    total = 0
    for i in string:
      total += (ord(i)-96)
    return total

  def fill_empty(self,size):
    for i in range(size):
      self.append(0)

  def mashing(self,number,index):
    i = self.hash_table.head
    for m in range(index):
      i = i.next
    if i.val == 0:
      i.val = number
    else:
      while i.elements:
        i = i.elements
      i.elements = node(number)
        
  def hashing(self,mod):
    cur = self.head
    self.hash_table = linked_list()
    self.hash_table.fill_empty(mod)
    while cur:
      ascci_val = self.get_ascii_val(cur.val)
      index = ascci_val % mod
      self.mashing(cur.val,index)
      cur = cur.next    

  def display_table(self,index):
    cur = self.hash_table.head
    for i in range(index):
      cur = cur.next
    print(cur.val,end = ' ')
    while cur.elements:
      cur = cur.elements
      print(cur.val, end=' ')
      
def main():
    elem_num = int(input()) - 2
    table_size = int(input())
    index = int(input())
    elements = linked_list()
    for i in range(elem_num):
        elements.append(input().strip())
    elements.hashing(table_size)
    elements.display_table(index)

if __name__ == "__main__":
  main()
