class node():
  def __init__(self, num):
    self.data = num
    self.next = None
class linked_list():
  def __init__(self):
    self.root = None
  def append(self,num):
    if self.root is None: self.root = node(num)
    else:
      cur = self.root
      while cur.next is not None:
        cur = cur.next
      cur.next = node(num)
  def display(self):
    cur = self.root
    if cur is None: 
      print("Empty")
      return
    while cur:
      print(cur.data, end=' ')
      cur = cur.next
    print('\n',end='')
  def sel_sort(self,it):
    if self.root is None: return
    cur = self.root
    i = 0
    while cur and i<it:
      smol = cur
      next = cur.next
      while next:
        if next.data < smol.data:
          smol = next
        next = next.next
      temp = cur.data
      cur.data = smol.data
      smol.data = temp
      cur = cur.next
      i += 1
    

def main():
  nums = int(input()) - 1
  it = int(input())
  ll = linked_list()
  for i in range(nums):
    ll.append(int(input()))
  ll.sel_sort(it)
  ll.display()


if __name__ == "__main__":
  main()