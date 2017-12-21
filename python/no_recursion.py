class no_recursion:
    def __init__(self):
        self.root = dict()
        self.depth = 1
    def get_depth(self):
        return self.depth
    def active(self):
        return self.root
    def prev(self):
        return self.root["&"]
    def push(self):
        ou = dict()
        ou["&"] = self.root
        self.root = ou
        self.depth += 1
        return ou
    def pop(self):
        self.root = self.root["&"]
        self.depth -= 1
