//
// Created by rishitg on 26/6/25.
//
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "listnode.h"

void displayContents(struct ListNode * const head) {
    if (head == NULL) return;
    struct ListNode* temp = head;
    struct ListNode* slow = NULL;
    struct ListNode* fast = NULL;
    if (checkCycle(head)) {
        printf("Printing Cyclic List!\n");
        struct ListNode* p = temp;
        struct ListNode* q = temp;

        while (q && q->next) {
            p = p->next;
            q = q->next->next;

            if (p == q) {
                p = temp;
                while (p->next != q->next) {
                    p = p->next;
                    q = q->next;
                }
                slow = p->next;
                fast = q;
                q->next = NULL;
            }
        }
    }

    printf("List: [");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("END]\n");

    if (fast) fast->next = slow;
}

void appendNode(struct ListNode * const head, struct ListNode * const node) {
    struct ListNode* temp = head;
    if (node == NULL || temp == NULL) return;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

void removeHead(struct ListNode** head) {
    if (head == NULL || *head == NULL) return;
    *head = (*head)->next;
}

void removeTail(struct ListNode * const head) {
    if (head == NULL) return;
    struct ListNode* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    temp->next = NULL;
}

void removeFromPosition(struct ListNode * const head, int pos) {
    if (pos > size(head)) return;
    int cnt = 1;
    struct ListNode* temp = head;
    while (cnt++ < pos) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

int size(struct ListNode * const head) {
    if (head == NULL) return 0;
    int cnt;
    struct ListNode* temp = head;
    cnt = 0;

    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

bool checkCycle(struct ListNode * const head) {
    if (head == NULL) return false;
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int getData(struct ListNode * const node) {
    if (node == NULL) return INT_MIN;
    return node -> data;
}

void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void removeCycle(struct ListNode* const head) {
    if (head == NULL) return;
    struct ListNode* p = head;
    struct ListNode* q = head;

    while (q && q->next) {
        p = p->next;
        q = q->next->next;

        if ( p == q ) {
            break;
        }
    }

    if (q == NULL || q->next == NULL) return;

    p = head;

    if (p == q) {
        while (q->next != p) {
            q = q->next;
        }
    }else {
        while (p->next != q->next) {
            p = p->next;
            q = q->next;
        }
    }

    q->next = NULL;

}

