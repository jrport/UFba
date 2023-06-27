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
  def swap(self,ad1,ad2):
    temp = ad1.data
    ad2.data = ad1.data
    ad1.data = temp
    return
  def ins_sort(self,it):
    cur = self.root
    ll1 = linked_list()
    i = 0
    while cur and i<it-1:
      next = cur.next
      if cur.data>cur.next.data:
        ll1.append(cur.next.data)
        self.swap(cur,cur.next)
        i += 1
      cur = cur.next
    ll1.append(self.root.data)
        

def main():
  nums = int(input()) - 1
  it = int(input())
  ll = linked_list()
  for i in range(nums):
    ll.append(int(input()))
  ll2 = ll.ins_sort(it)
  ll2.display()


if __name__ == "__main__":
  main()