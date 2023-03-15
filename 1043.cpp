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
	e = stack->data[stack->top--];
}
int main() {
    Stack* stack;
    init(stack);
   	char c;
    while(~scanf("%c", &c)) {
    	char next = getchar();
        if(c >= '0' && c <= '9') {
       		push(stack, c-'0');
        } else {
            int n1, n2;
            pop(stack, n1);
            pop(stack, n2);
        	if(c == '+') {
                push(stack, n2+n1);
            } else if(c == '-') {
            	push(stack, n2-n1);
            } else if(c == '*') {
            	push(stack, n2*n1);
            } else {
            	push(stack, n2/n1);
            }
        }
        if(next == '#') {
        	break;
        }
    }
    printf("%d", top(stack));

	return 0;
}
