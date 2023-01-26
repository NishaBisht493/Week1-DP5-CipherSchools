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

ListNode* reverseLLInGroup(ListNode* head, int K){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    int k = 0;
    while(curr != nullptr && k < K){
        k++;
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if(next != nullptr){
        head->next = reverseLLInGroup(next, K);
    }
    return head;
}

int main(){

}