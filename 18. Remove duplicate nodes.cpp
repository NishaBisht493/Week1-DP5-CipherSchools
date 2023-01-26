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

ListNode* removeDuplicateNodes(ListNode* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* curr = head;
    ListNode* next = nullptr;
    while(curr->next != nullptr){
        if(curr->val == curr->next->val){
            next = curr->next;
            curr->next = next->next;
            delete(next);
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}

int main(){

}