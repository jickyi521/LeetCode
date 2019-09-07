def deeptraverse(this, view):
    if len(view.subViews) == 0:
            print(view)
    else:
      for view in view.subViews:
        if len(view) == 0:
            print(view)
        else:
            print(view)
            this.deeptraverse(view)
    

#https://blog.csdn.net/mingwanganyu/article/details/72033122
#先遍历节点 -> 左子树 -> 右子数  用堆栈的数据结构，先进后出
def deepTraverse2(root):
  stack = Stack()
  stack.push(root)
  while stack.isNotEmpty():
    node = stack.pop()
    print(node.val) #遍历根节点
    if node.rightNode:
      stack.push(node.rightNode)
    if node.leftNode:
      stack.push(node.leftNode)
