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

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    
    ListNode* result = nullptr;
    if(a == nullptr) return b;
    else if(b == nullptr) return a;
    else{
        
        if(a->val <= b->val){
            result = a;
            result->next = mergeTwoLists(a->next, b);
        }
        else{
            result = b;
            result->next = mergeTwoLists(a, b->next);
        }
        return result;
    }
    return result;
}
int main(){

}