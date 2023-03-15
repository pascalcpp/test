#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    char data;
    struct Node* next;
}Node;

void split(Node* &head, Node* &h1, Node* &h2, Node* &h3) {
    Node* cur = head->next;
    Node* t1 = h1, * t2 = h2, * t3 = h3;
    t1->next = h1, t2->next = h2, t3->next = h3;
    while(cur != nullptr) {
        Node* next = cur->next;
        if(cur->data >= '0' && cur->data <= '9') {
            t1->next = cur;
            t1 = t1->next;
            t1->next = h1;
        } else if((cur->data >= 'a' && cur->data <= 'z')
                  || (cur->data >= 'A' && cur->data <= 'Z')) {
            t2->next = cur;
            t2 = t2->next;
            t2->next = h2;
        } else {
            t3->next = cur;
            t3 = t3->next;
            t3->next = h3;
        }
        cur = next;
    }
}
int main() {
    Node* head = new Node;
    head->next = nullptr;
    head->data = '\0';
    Node* tail = head;
    char c;
    while(scanf("%c", &c)) {
        if(c == '\n') {
            break;
        }
        tail->next = new Node;
        tail = tail->next;
        tail->data = c;
        tail->next = nullptr;
    }
    Node* h1 = new Node, *h2 = new Node, *h3 = new Node;
    h1->data = '\0', h2->data = '\0', h3->data = '\0';
    split(head, h1, h2, h3);
    Node* cur = h1->next;
    while(cur->data != '\0') {
        printf("%c", cur->data);
        cur = cur->next;
    }
    printf("\n");
    cur = h2->next;
    while(cur->data != '\0') {
        printf("%c", cur->data);
        cur = cur->next;
    }
    printf("\n");
    cur = h3->next;
    while(cur->data != '\0') {
        printf("%c", cur->data);
        cur = cur->next;
    }
    printf("\n");
    return 0;
}
