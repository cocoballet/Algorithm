/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ret(0);
        ListNode *r = &ret;
        int sum = 0;
        while (l1 || l2 || sum) {
            sum += (l1? l1->val : 0) +(l2? l2->val : 0);
            r->next = new ListNode(sum % 10);
            r = r->next;
            l1 = l1? l1->next : l1;
            l2 = l2? l2->next : l2;
            sum = sum/10;
        }
        return ret.next;
    }
