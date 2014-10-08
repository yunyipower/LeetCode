/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode * rotateRight(ListNode *head,unsigned rotate_num){
        if(!head) return NULL;
        
        ListNode *node = head,*tail = head,*ret = NULL;
        unsigned length = 0;


        while(node){
            ++length;
            node = node->next;
            if(node) tail = node;
        }

        rotate_num %= length;

        unsigned cur_num = 1;node = head;
            while(cur_num++ != length-rotate_num)
            node = node->next;

        tail->next = head;
        ret = node->next;
        node->next = NULL;
    
        return ret;
    }
    
};