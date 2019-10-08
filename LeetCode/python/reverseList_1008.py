
#https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode/
#1 → 2 → 3 → Ø，我们想要把它改成 Ø ← 1 ← 2 ← 3
def reverseList(headNode):
    if headNode  is None or headNode.next is None:
        return headNode
    
    headNode = reverseList(headNode.next)
    headNode.next.next = headNode
    headNode.next = None
    

def reverseList2(headNode):
    preNode = None
    currNode = headNode
    while currNode != None:
        nextNode = currNode.nextNode
        currNode.nextNode = preNode
        preNode = currNode
        currNode = nextNode
    return preNode