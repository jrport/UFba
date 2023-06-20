class tree_node():
    def __init__(self,num):
        self.value = num
        self.right = None
        self.left = None

class btree():
    def __init__(self):
        self.root = None
    def Add(self,root,num):
        if self.root is None: self.root = tree_node(num)
        elif num > root.value:
            if root.right is None: root.right = tree_node(num)
            else: root = self.Add(root.right,num)
        else:
            if root.left is None: root.left = tree_node(num)
            else: root = self.Add(root.left,num)
    def find_p_target(self,root,num):
    #     if (num == root.right.value)or(num == root.left.value):
    #         return root
    #     if num > root.value: 
    #         self.find(root.right,num)
    #     elif num < root.value:
    #         self.find(root.left, num)
    #     return -1
    # def find(self,root,num):
    #     if num == root.value:  return root
    #     if num > root.value: 
    #         root = root.right
    #         self.find(root.right,num)
    #     elif num < root.value:
    #         root = root.left
    #         self.find(root.left, num)
    #     return -1
    # def remove(self, num):
    #     target = self.find(self.root,num)
    #     if target.value != self.root.value:
    #         p_target = self.find_p_target(self.root,num)
    #     target = self.find(self.root,num)
    #     if (target.right is None)and(target.left is None):
    #         if target.value == self.root.value:
    #             self.root = None
    #         elif p_target.value>target.value: p_target.left is None
    #         else: p_target.right is None
    #     elif (target.right is None)or(target.left is None):
    #         if target.value == self.root.value:
    #             if self.root.right is not None:
    #                 temp = self.root
    #                 self.root = self.root.right
    #                 temp.right = None
    #             else:
    #                 temp = self.root
    #                 self.root = self.root.left
    #                 temp.left = None
    #         else:
    #             if target.value == p_target.right.value:
    #                 if target.right is not None: p_target.right = target.right
    #                 else: p_target.right = target.left
    #             elif target.value == p_target.left.value:
    #                 if target.right is not None: p_target.left = target.right
    #                 else: p_target.left = target.left
    #     else:
    #         pred = target.left
    #         while pred.right is not None:
    #             pred = pred.right
    #         pred.right = target.right
    #         p_target = self.find_p_target(self.root,tager)
    #         p_pred = self.find_p_target(self.root,pred)
    #         if p_target.value == p_target.right.value:
    #             p_target.right = pred
    #         else: p_target.left = pred
    #         p_pred.right = pred.left
    #         pred.left = target.left
    #         target.right = None
    #         target.left = None
    def InOrder(self,root):
        if root is not None:
            self.InOrder(root.left)
            print(root.value)
            self.InOrder(root.right)

def main():
    size = int(input())
    tree = btree()
    vector = [50,10,60,5,30,55,70,20,35,33]
    #vector = [int(i) for i in input().split()]
    for i in vector:
        tree.Add(tree.root,i)
    tree.InOrder(tree.root)
    tree.remove(50)
    tree.InOrder(tree.root)

if __name__ == "__main__":
    main()