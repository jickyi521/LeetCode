
def addTwoNumbers:(l1, l2)
    l3 = ListNode(-1)
    carry  = 0
    while l1 or l2:
        temp = l1 && l1.val or 0 + l2 && l2.val or 0 + carry
        carry = temp / 10
        l3.next = ListNode(temp % 10)
        l3 = l3.next
        l1 = l1.next
        l2 = l2.next
    
    return l3