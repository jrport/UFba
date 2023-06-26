class min_heap():
    def __init__(self):
        self.heap = []
    def parent(self,i):
        return (i-1)//2
    def get_left_index(self,i):
        return (2*i)+1
    def get_right_index(self,i):
        return (2*i)+2
    def swap(self,i,j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]
    def fix_up(self,i):
        while i>0 and self.heap[i]<self.heap[self.parent(i)]:
            self.swap(i,self.parent(i))
            i = self.parent(i)
    def add(self,i):
        self.heap.append(i)
        self.fix_up(len(self.heap)-1)
    def fix_down(self,i):
        min = i
        left = self.get_left_index(i)
        right = self.get_right_index(i)
        size = len(self.heap)

        if left < size and self.heap[left] < self.heap[min]:
            min = left

        if right < size and self.heap[right] < self.heap[min]:
            min = right

        if min != i:
            self.swap(i, min)
            self.fix_down(min)
    def pop(self):    
        min_el = self.heap[0]
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        self.fix_down(0)
        return min_el
    def PreOrder(self):
        self.PreOrderCall(0)
        print("")

    def PreOrderCall(self, i):
        if i >= len(self.heap):
            return
        left_child = self.get_left_index(i)
        right_child = self.get_right_index(i)

        print(self.heap[i], end = ' ')
        self.PreOrderCall(left_child)
        self.PreOrderCall(right_child)

def main():
    a = input()
    heap = min_heap()
    vector = [int(i) for i in input().split()]
    rem_nums = []
    for i in vector:
        heap.add(i)
    rem_num = int(input())
    for i in range(rem_num):
        rem_nums.append(heap.pop())
        heap.PreOrder()
    for i in rem_nums:
        print(i,end=' ')

if __name__ == "__main__":
    main()
    