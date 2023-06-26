class MinHeap:
    def __init__(self):
        self.heap = []

    def parent(self, i):
        return (i - 1) // 2

    def left_child(self, i):
        return 2 * i + 1

    def right_child(self, i):
        return 2 * i + 2

    def swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    def heapify_up(self, i):
        while i > 0 and self.heap[i] < self.heap[self.parent(i)]:
            self.swap(i, self.parent(i))
            i = self.parent(i)

    def heapify_down(self, i):
        smallest = i
        left = self.left_child(i)
        right = self.right_child(i)
        size = len(self.heap)

        if left < size and self.heap[left] < self.heap[smallest]:
            smallest = left

        if right < size and self.heap[right] < self.heap[smallest]:
            smallest = right

        if smallest != i:
            self.swap(i, smallest)
            self.heapify_down(smallest)

    def insert(self, item):
        self.heap.append(item)
        self.heapify_up(len(self.heap) - 1)

    def extract_min(self):
        if len(self.heap) == 0:
            raise IndexError("Heap is empty.")
        
        min_element = self.heap[0]
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        self.heapify_down(0)

        return min_element

    def get_min(self):
        if len(self.heap) == 0:
            raise IndexError("Heap is empty.")

        return self.heap[0]

    def is_empty(self):
        return len(self.heap) == 0

    def size(self):
        return len(self.heap)

    def preorder_traversal(self):
        def preorder_recursive(i):
            if i >= len(self.heap):
                return

            print(self.heap[i], end=" ")  # Process the current element
            preorder_recursive(self.left_child(i))  # Recurse on the left child
            preorder_recursive(self.right_child(i))  # Recurse on the right child

        preorder_recursive(0)  # Start the recursive traversal from the root (index 0)
        print()  # Print a newline after the traversal

def main():
    heap = MinHeap()
    heap.insert(1)
    heap.insert(2)
    heap.insert(4)
    heap.preorder_traversal()


if __name__ == "__main__":
    main()