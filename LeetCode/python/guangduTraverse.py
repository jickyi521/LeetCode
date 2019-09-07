def guangdutraverse(this, view):
    s = []
    if len(view.subViews) == 0:
            print(view)
    else:
      for view in view.subViews:
        print(view)
        if len(view.subViews) != 0:
            s.append(view)
      for sItem in s:
          this.guangdutraverse(sItem)

def guangdutraverse2(root)
   queue = Queue()
   queue.push(root)
   while queue.isNotEmpty():
     node = queue.pop()
     print(node.val)
     if node.leftNode:
       queue.push(node.leftNode)
     if node.rightNode:
       queue.push(node.rightNode)