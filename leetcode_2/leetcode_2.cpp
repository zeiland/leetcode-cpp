#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* append(ListNode *tail, int val){
        ListNode* new_tail = new ListNode(val);
        tail->next = new_tail;
        return new_tail;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val + l2->val + carry;
            int val = sum % 10;
            carry = sum / 10;
            tail = append(tail, val);
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            int sum = l1->val + carry;
            int val = sum % 10;
            carry = sum / 10;
            tail = append(tail, val);
            l1 = l1->next;
        }
        while(l2 != nullptr){
            int sum = l2->val + carry;
            int val = sum % 10;
            carry = sum / 10;
            tail = append(tail, val);
            l2 = l2->next;
        }
        if(carry != 0){
            append(tail,carry);
        }
        ListNode* ret = head->next;
        delete head;
        return ret;
    }
};