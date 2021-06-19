

# 二叉树 https://time.geekbang.org/column/article/68334

def find(tree, data):
    node = tree
    while node:
        if node.data == data:
            return node
        elif node.data > data:
            node = node.leftNode
        else:
            node = node.rightNode

def insert(tree, data):
    node = tree
    while node:
        if data > node.data:
            if node.rightNode is None:
                newNode = Node(data)
                node.rightNode = newNode
            else:
                node = node.rightNode
        else:
            if node.leftNode is None:
                newNode = Node(data)
                node.leftNode = newNode
            else:
                node = node.leftNode

def delete(tree, data):
    p = tree
    pp = None # p的父节点
    while p and p.data != data:
        pp = p
        if data < p.data:
            p = p.leftNode
        else:
            p = p.rightNode    

    if p == None:
        return #没有找到data

    #删除的节点有两个叶子节点
    if p.leftNode and p.rightNode:
        minP = p.rightNode
        minPP = p
        while minP:
            minPP = minP
            minP = minP.leftNode
        
        p.data = minP.data
        p = minP
        pp = minPP

    if p.leftNode:
        child = p.leftNode
    elif p.rightNode:
        child = p.rightNode
    else:
        child = None
    
    if pp is None:
        tree = child
    elif pp.leftNode == p:
        pp.leftNode = child
    else:
        pp.rightNode = child 