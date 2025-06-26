//
// Created by rishitg on 25/6/25.
//


#ifndef LISTNODE_H
#define LISTNODE_H
#include<stdbool.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

void displayContents(struct ListNode* const head);
void appendNode(struct ListNode* const head, struct ListNode* const node);
void removeHead(struct ListNode** head);
void removeTail(struct ListNode* const head);
void removeFromPosition(struct ListNode* const head, int pos);
int size(struct ListNode* const head);
bool checkCycle(struct ListNode* const head);
void removeCycle(struct ListNode* const head);
int getData(struct ListNode* const node);
void freeList(struct ListNode* head);

#endif