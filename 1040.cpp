#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int cof;
    int p;
    struct Node* next;
}Node;

int main() {
    Node* h1 = new Node;
    h1->next = nullptr;
    Node* cur = h1;
    int n1, n2;
    while(scanf("%d,%d", &n1, &n2)) {
        if(n1 == 0 && n2 == 0) {
            break;
        }
        cur->next = new Node;
        cur = cur->next;
        cur->cof = n1, cur->p = n2;
        cur->next = nullptr;
    }
    Node* h2 = new Node;
    h2->next = nullptr;
    cur = h2;
    while(scanf("%d,%d", &n1, &n2)) {
        if(n1 == 0 && n2 == 0) {
            break;
        }
        cur->next = new Node;
        cur = cur->next;
        cur->cof = n1, cur->p = n2;
        cur->next = nullptr;
    }
    Node *c1 = h1->next, *c2 = h2->next;
    Node* newHead = new Node;
    Node* pNode = newHead;
    while(c1 != nullptr && c2 != nullptr) {
        if(c1->p == c2->p) {
        	pNode->next = new Node;
            pNode->next->cof = c1->cof + c2->cof;
            pNode->next->p = c1->p;
            c1 = c1->next, c2 = c2->next;
        } else if(c1->p < c2->p) {
            pNode->next = new Node;
            pNode->next->cof = c1->cof;
            pNode->next->p = c1->p;
            c1 = c1->next;
        } else {
            pNode->next = new Node;
            pNode->next->cof = c2->cof;
            pNode->next->p = c2->p;
            c2 = c2->next;
        }
        pNode = pNode->next;
    }
    if(c2 != nullptr) {
    	pNode->next = c2;
    }
    if(c1 != nullptr) {
    	pNode->next = c1;
    }
    pNode = newHead->next;
    int count = 0;
    while(pNode != nullptr) {
        if(pNode->cof != 0) {
            if(count != 0) {
               printf("+%dx^%d", pNode->cof, pNode->p);
            } else {
               printf("%dx^%d", pNode->cof, pNode->p);
            }
            count++;
        }

        pNode = pNode->next;
    }
    return 0;
}
