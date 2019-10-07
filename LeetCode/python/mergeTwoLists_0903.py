

def mergeTwoLists(self, l1, l2):
    if l1 is None:
        return l2
    elif l2 is None:
        return l1
    elif l1.val < l2.val:
        l1.next = self.mergeTwoLists(l1.next, l2)
        return l1
    else:
        l2.next = self.mergeTwoLists(l1, l2.next)
        return l2



def mergeTwoList2(self, l1, l2):
    head = ListNode(-1)
    while l1 || l2:
        if l1.val < l2.val:
            head = ListNode(l1.val)
            l1 = l1.next 
        else:
            head = ListNode(l2.val)
            l2 = l2.next
        head = head.next

    if l1 is not None:
        head.next = l1
    if l2 is not None:
        head.next = l2
    
    return head