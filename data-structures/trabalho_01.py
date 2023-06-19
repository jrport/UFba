class node();
    def __init__(int n):
        self.data = n
        self.next = None


class linked_list():
    def __init__():
        self.head = None
    def make_head(node n):
        self.head = n
    def check_ciclo():
        slow = self.head
        fast = self.head
        while slow.next != None:
            slow = slow.next
            fast = fast.next.next
            if fast == None:
                print("Nenhum ciclo")
                break
            if fast == slow:
                print("Ciclo detectado")

def main():
    input()
    n = [int(i) for i in input().split]
    for i in range(len(n)):
        node


