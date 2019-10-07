
def removeNumFromEnd(head, n):
    dummy = ListNode(0)
    dummy.next = head
    fast = slow = dummy
    
    while n and fast:
        fast = fast.next
        n -= 1

    if fast.next and slow.next:
        fast = fast.next
        slow = slow.next
    
    slow.next = slow.next.next

    return dummy.next


def removeNumFromEnd2(head, n): 
    dummy = ListNode(0)
    dummy.next = head
    temp = dummy
    length = 0

    while temp is not None:
        length += 1
        temp = temp.next

    length -= n
    temp = dummy

    while length>0:
        length -= 1
        temp = temp.next
    
    temp = temp.next.next

    return dummy.next
