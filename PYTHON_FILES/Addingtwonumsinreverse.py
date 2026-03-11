from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        res = dummy
        total = carry = 0
        while l1 or l2 or carry:
            total = carry
            if l1:
                total += l1.val
                l1 = l1.next
            if l2:
                total += l2.val
                l2 = l2.next
            num = total % 10
            carry = total // 10
            dummy.next = ListNode(num)
            dummy = dummy.next
        return res.next

def list_to_linked(lst):
    dummy = ListNode()
    curr = dummy
    for num in lst:
        curr.next = ListNode(num)
        curr = curr.next
    return dummy.next

l1 = list_to_linked([2,3,4])
l2 = list_to_linked([5,6,7])
s = Solution()
result = s.addTwoNumbers(l1, l2)

# Print result as a list for clarity
output = []
while result:
    output.append(result.val)
    result = result.next
print(output)