#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

bool isCyclePresent(struct ListNode* head);
void removeLoopAndPrint(struct ListNode* head);

int main(int argc, char* argv){
    struct ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* p = head;
    
    p->val = 1;
    p->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    
    p = p->next;
    
    p->val = 7;
    p->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* q = p;

    p = p->next;
    
    p->val = 3;
    p->next = (struct ListNode*) malloc(sizeof(struct ListNode));

    p = p->next;

    p->val = 6;
    p->next = q;

    printf("IsCyclePresent => %d\n", isCyclePresent(head));
    removeLoopAndPrint(head);

    return 0;
}

bool isCyclePresent(struct ListNode* head){
    bool res = false;
    struct ListNode* p = head;
    struct ListNode* q = head;

    while(q && q->next){
        p = p -> next;
        q = q -> next -> next;

        if(p == q){
            res = true;
            break;
        }
    }

    return res;
}

void removeLoopAndPrint(struct ListNode* head){
    struct ListNode* p = head;
    struct ListNode* q = head;

    while(q && q->next){
        p = p->next;
        q = q->next->next;

        if(p == q) break;
    }

    if(p != q) return;

    p = head;

    while(p->next != q->next){
        p = p->next;
        q = q->next;
    }

    q->next = NULL;

    p = head;

    while(p){
        printf("Value at %p: %d\n", p, p->val);
        p = p -> next;
    }
}