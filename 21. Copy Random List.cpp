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

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr) {}
};

// Node* copy(Node* head){
//     unordered_map<Node*, Node*> hash;
//     Node* ptr = head;
//     while(ptr != nullptr){
//         Node* copiedNode = new Node(ptr->val);
//         hash[ptr] = copiedNode;
//         ptr = ptr->next;
//     }

//     ptr = head;
//     while(ptr != nullptr){
//         // Node* next = ptr->next;
//         // Node* random = ptr->random;
//         Node* copied = hash[ptr];
//         copied->next = hash[ptr->next];
//         copied->random = hash[ptr->random];
//         ptr = ptr->next;
//     }

//     return hash[head];
// }

Node* copy(Node* head){
    if(head == nullptr){
        return nullptr;
    }
    Node* ptr = head;
    Node* qtr = nullptr;

    while(ptr != nullptr){
        qtr = ptr->next;
        Node* newNode = new Node(ptr->val);
        newNode->next = qtr;
        ptr->next = newNode;

        ptr = qtr;
    }

    ptr = head;
    qtr = head->next;
    while(ptr != nullptr && qtr != nullptr){
        qtr = ptr->next;
        if(ptr->random != nullptr){
            qtr->random = ptr->random->next;
        }
        else{
            qtr->next = nullptr;
        }
        ptr = qtr->next;
    }

    Node* newHead = head->next;
    ptr = head;
    while(ptr != nullptr && ptr->next != nullptr){
        qtr = ptr->next;
        ptr->next = qtr->next;
        ptr = qtr;
    }

    return newHead;
}

int main(){

}