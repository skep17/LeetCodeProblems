/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 is null && l2 is null) return null;

        ListNode result = new ListNode();
        
        int curSum = 0;
        int carry = 0;

        if (l1 is not null) curSum += l1.val;
        if (l2 is not null) curSum += l2.val;

        if (curSum > 9)
        {
            carry = 1;
            curSum %= 10;
        }

        result.val = curSum;

        if (carry > 0)
        {
            if (l1 is not null)
            {
                if (l1.next is not null)
                {
                    l1.next.val += 1;
                }
                else
                {
                    l1.next = new ListNode(1);
                }
            }
            else
            {
                l1 = new ListNode(0,new ListNode(1));
            }
        }

        result.next = AddTwoNumbers(l1?.next, l2?.next);

        return result;
    }
}