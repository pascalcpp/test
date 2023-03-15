#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
	int data;
    struct Stack* next;
}Stack;

void init(Stack *& stack){
	stack = new Stack;
    stack->next = nullptr;
}
void push(Stack *& stack, int e) {
	Stack* node = new Stack;
    node->data = e;
    node->next =  stack->next;
    stack->next = node;
}
int top(Stack *& stack) {
	return stack->next->data;
}
bool empty(Stack *& stack) {
	return stack->next == nullptr;
}
void pop(Stack *& stack, int &e) {
    if(empty(stack)) {
    	return;
    }
	Stack* node = stack->next;
    stack->next = stack->next->next;
    e = node->data;
 	free(node);
}

int count(Stack* &stack) {
	Stack* cur = stack->next;
    int c = 0;
    while(cur != nullptr) {
    	c++;
        cur = cur->next;
    }
    return c;
}
int main() {
    Stack* stack;
    init(stack);
	int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
    	int e;
        scanf("%d", &e);
        push(stack, e);
    }
    int n;
    scanf("%d", &n);
	for(int i = 0; i < n; i++) {
    	int e;
        pop(stack, e);
    }
    if(empty(stack)) {
    	printf("-1");
    } else {
    	printf("%d", top(stack));
    }
	return 0;
}
