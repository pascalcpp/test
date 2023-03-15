#include<stdio.h>
typedef struct{
	int data[10000];
	int top;
}Stack;

void init(Stack *& stack){
	stack = new Stack;
    stack->top = -1;
}
void push(Stack *& stack, int e) {
	stack->data[++stack->top] = e;
}
int top(Stack *& stack) {
	return stack->data[stack->top];
}
bool empty(Stack *& stack) {
	return stack->top == -1;
}
void pop(Stack *& stack, int &e) {
    if(empty(stack)) {
        return;
    }
	e = stack->data[stack->top--];
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
