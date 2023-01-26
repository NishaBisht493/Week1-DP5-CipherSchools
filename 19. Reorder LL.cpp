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

ListNode* reorder(ListNode* head, int K){
    if(head == nullptr || head->next == nullptr || K == 0){
        return head;
    }
    ListNode* p = head;
    ListNode* q = nullptr;

    int k = 0;
    while(p != nullptr && k < K){
        k++;
        p = p->next;
    }
    if(p == nullptr){
        return head;
    }
    q = head;
    while(p->next != nullptr && q != nullptr){
        p = p->next;
        q = q->next;
    }
    p->next = head;
    head = q->next;
    q->next = nullptr;

    return head;

}

int main(){

}