class Node:
    def __init__(self, num):
        self.val = num
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, num):
        if self.head is None:
            self.head = Node(num)
        else:
            cur = self.head
            while cur.next:
                cur = cur.next
            cur.next = Node(num)
    
    def display(self):
        if self.head is None:
            print("Empty")
            return
        cur = self.head
        while cur:
            print(cur.val, end=" ")
            cur = cur.next
        print()
    
    def get_node_at_index(self, index):
        cur = self.head
        for i in range(index):
            if cur is None:
                return None
            cur = cur.next
        return cur
    
    def quick_sort_call(self,pivot):
        if self.head is None or self.head.next is None:
            return self
        pivot_node = self.get_node_at_index(pivot)
        pivot_val = pivot_node.val
        cur = self.head
        left_side = LinkedList()
        right_side = LinkedList()
        while cur:
            if cur.val > pivot_val: right_side.append(cur.val)
            elif cur.val < pivot_val: left_side.append(cur.val)
            cur = cur.next
        print(left_side.head.val,right_side.head.val,end=' ')
        left_sorted = left_side.quick_sort()
        right_sorted = right_side.quick_sort()
        sorted = LinkedList()
        sorted.head = left_sorted.head
        sorted.append(pivot_val)
        cur = sorted.head
        while cur.next:
            cur = cur.next
        cur.next = right_sorted.head

        return sorted


    def quick_sort(self):
        if self.head is None or self.head.next is None:
            return self
        pivot_node = self.get_node_at_index(0)
        pivot_val = pivot_node.val
        cur = self.head
        left_side = LinkedList()
        right_side = LinkedList()
        while cur:
            if cur.val > pivot_val: right_side.append(cur.val)
            elif cur.val < pivot_val: left_side.append(cur.val)
            cur = cur.next
        left_sorted = left_side.quick_sort()
        right_sorted = right_side.quick_sort()
        sorted = LinkedList()
        sorted.head = left_sorted.head
        sorted.append(pivot_val)
        cur = sorted.head
        while cur.next:
            cur = cur.next
        cur.next = right_sorted.head

        return sorted


def main():
    num_el = int(input())
    pivot_index = int(input())
    linked_list = LinkedList()
    for i in range(num_el-1):
        element = int(input())
        linked_list.append(element)
    sorted_list = linked_list.quick_sort_call(pivot_index)
    sorted_list.display()


if __name__ == "__main__":
    main()
