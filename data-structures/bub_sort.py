class node:
    def __init__(self, num):
        self.data = num
        self.next = None


class linked_list:
    def __init__(self):
        self.root = None

    def append(self, num):
        if self.root is None:
            self.root = node(num)
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
            print(cur.data, end=" ")
            cur = cur.next
        print("\n", end="")

    def swap(self, ad1, ad2):
        temp = ad2.data
        ad2.data = ad1.data
        ad1.data = temp
        return

    def bub_sort(self, it):
        for i in range(it):
            cur = self.root
            while cur.next:
                if cur.data > cur.next.data:
                    self.swap(cur, cur.next)
                cur = cur.next


def main():
    nums = int(input()) - 1
    it = int(input())
    ll = linked_list()
    for i in range(nums):
        ll.append(int(input()))
    ll.bub_sort(it)
    ll.display()


if __name__ == "__main__":
    main()
