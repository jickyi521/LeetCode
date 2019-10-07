
def swapPairs(head):

    if head is None or head.next is None:
        return head

    next = head.next
    head.next = swapPairs(next.next)
    next.next = head

    return next

# 1->2->3->4   2->1->4->3 TODO
