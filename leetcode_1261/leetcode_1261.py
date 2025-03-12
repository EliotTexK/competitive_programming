class FindElements:
    def add_nodes_to_hashtable(self, subtree: Optional[TreeNode], val: int):
        self.hashtable.add(val)
        if subtree.left != None:
            self.add_nodes_to_hashtable(subtree.left, 2 * val + 1)
        if subtree.right != None:
            self.add_nodes_to_hashtable(subtree.right, 2 * val + 2)

    def __init__(self, root: Optional[TreeNode]):
        self.hashtable = set() # "JUST THROW A HASHTABLE AT IT!!!"
        if root != None:
            self.add_nodes_to_hashtable(root,0)

    def find(self, target: int) -> bool:
        return target in self.hashtable