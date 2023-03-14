#include<stdio.h>
#include<stdlib.h>
#define MAXVALUE 1024
typedef struct {
	int front, rear;
    char data[MAXVALUE];
    int size;
}Q, *Queue;
void initQueue(Queue & queue) {
	queue = (Queue)malloc(sizeof(Q));
    queue->size = 0;
    queue->front = 0;
    queue->rear = 0;
}
void enQueue(Queue queue, char e) {
	if((queue->rear+1)%MAXVALUE == queue->front) {
    	//TODO
    	// full
        return;
    }
    queue->data[(++queue->rear)%MAXVALUE] = e;
    queue->size++;
}
void deQueue(Queue queue, char& e) {
	if(queue->front == queue->rear) {
    	return;
    }
    e = queue->data[(++queue->front)%MAXVALUE];
    queue->size--;
}
int main() {
	Queue q1, q2;
    initQueue(q1);
	initQueue(q2);
    int n1, n2;
    scanf("%d", &n1);
    getchar();
    for(int i = 0; i < n1; i++) {
    	char temp;
        scanf("%c", &temp);
        getchar();
        enQueue(q1, temp);
    }

    scanf("%d", &n2);
    getchar();
    for(int i = 0; i < n2; i++) {
        char temp;
        scanf("%c", &temp);
        getchar();
        enQueue(q2, temp);
    }
    int round;
    scanf("%d", &round);
    char c1, c2;
    for(int i = 0; i < round; i++) {
        deQueue(q1, c1);
        deQueue(q2, c2);
    }
    printf("%c %c", c1, c2);
    return 0;
}
