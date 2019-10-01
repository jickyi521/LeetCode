
def removeNumFromEnd:(head, n)
    dummy = ListNode(-1)
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