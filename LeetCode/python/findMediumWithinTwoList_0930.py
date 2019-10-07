
def findMediumWithinTwoList(self, l1, l2):
    l3 = ListNode()
    if l1.val < l2.val:
        l3 = ListNode(l1.val)
        self.findMediumWithinTwoList(l1.next, l2)
    if l1.val >= l2.val
        self.findMediumWithinTwoList(l1, l2.next)

        

