#incldue<stdio.h>
typedef struct{
	char data[10000];
	int top;
}Stack;

void init(Stack *& stack){
	stack = new Stack;
    stack->top = -1;
}
void push(Stack *& stack, char e) {
	stack->data[++stack->top] = e;
}
char top(Stack *& stack) {
	return stack->data[top];
}
bool empty(Stack *& stack) {

	return stack->top == -1;
}
void pop(Stack *& stack, char &e) {
	e = stack->data[stack->top--];
}
// * *
// 2 * 1 * 3 + 4
// 2 1 3 * *
int main() {
	Stack* stack;
    init(stack);
    char c;
    while(~scanf("%c", &c)) {
    	if(c == '\n') {
        	break;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
       		if(!empty(stack)) {
            	if(c == '(') {
                	push(stack, c);
                } else if(c == ')') {
                    char t;
                	while(top(stack) != '(') {                 	
                        pop(stack, t);
                        printf("%c", t);
                    }
                    pop(stack, t);
                } else if(c == '+' || c == '-') {
                    char t;
                	while(!empty(stack) && (top(stack) == '/' || top(stack) == '*')) {
                    	pop(stack, t);
                       	printf("%c", t);
                    }
                    push(stack, c);
                } else {
                	push(stakc, c);
                }
            }else {
            	push(stack, c);
            }
        } else {
        	printf("%c", c);
        }
    }
    while(!empty(stack)) {
    	char e;
        pop(stack, e);
        printf("%c", e);
    }

	return 0;
}
