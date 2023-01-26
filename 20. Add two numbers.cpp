#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
    if(a == nullptr) return b;
    else if(b == nullptr) return a;
    else{
        ListNode dummy(0);
        ListNode* p = a;
        ListNode* q = b;
        ListNode* r = &dummy;
        int carry = 0, sum = 0;
        while(p != nullptr || q != nullptr){
            sum = (p == nullptr ? 0 : p->val) + (q == nullptr ? 0 : q->val) + carry;
            carry = sum / 10;
            sum = sum % 10;
            r->next = new ListNode(sum);
            r = r->next;

            if(p != nullptr) p = p->next;
            if(q != nullptr) q = q->next;
        }

        if(carry > 0){
            r->next = new ListNode(carry);
        }
        return dummy.next; 
    }   
}

int main(){

}    