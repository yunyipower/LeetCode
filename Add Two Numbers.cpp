class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(!l1&&!l2) return NULL;
        if(!l1||!l2) return l1?l1:l2;

        int overdigit = 0;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *phead = NULL;
        ListNode *pbody = NULL;

        while(p1&&p2){
            int each_digit_val = p1->val + p2->val + overdigit;

            ListNode *pnew = new ListNode(each_digit_val%10);
            if(!phead) phead = pnew;

            if(!pbody) pbody = pnew;
            else{
                pbody->next = pnew;
                pbody = pnew;
            }

            if(each_digit_val>=10) overdigit = 1;
            else overdigit = 0;

            p1 = p1->next;p2 = p2->next;
        }

        ListNode *p3 = p1?p1:p2;
        while(p3||overdigit==1){
            ListNode *pnew = new ListNode(p3?((p3->val + overdigit)%10):overdigit);
            pbody->next = pnew;
            pbody = pnew;

            if(((p3?(p3->val):0) + overdigit)>=10) overdigit = 1;
            else overdigit = 0;
            p3 = p3?p3->next:NULL;
        }
        return phead;
    }
};