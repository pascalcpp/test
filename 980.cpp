#include<stdio.h>
#include<stdlib.h>
typedef struct BinNode{
	char data;
    BinNode* left;
    BinNode* right;
}BinNode;
typedef struct Queue{
    BinNode* data[1024];
    int size;
    int maxSize;
	int rear, front;
}Queue;
void enQueue(Queue* & queue, BinNode* &node) {
	queue->data[(++queue->rear)%queue->maxSize] = node;
    queue->size++;
}

void deQueue(Queue* & queue, BinNode* &node) {
	node = queue->data[(++queue->front)%queue->maxSize];
    queue->size--;
}
bool empty(Queue* & queue) {
	if(queue->front == queue->rear) {
    	return true;
    }
    return false;
}
BinNode* preTraverseBuild() {

    char c;
    scanf("%c", &c);
    if(c == '#') {
    	return nullptr;
    }

    BinNode* node = (BinNode*)malloc(sizeof(BinNode));
    node->data = c;
    node->left = preTraverseBuild();
    node->right = preTraverseBuild();
    return node;
}

int main() {
    BinNode* node = preTraverseBuild();
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->maxSize = 1000;
    queue->rear = -1, queue->front = -1;
    queue->size = 0;
    enQueue(queue, node);
    
    while(!empty(queue)) {
        int s = queue->size;
        for(int i = 0; i < s; i++) {
        	BinNode* p;
            deQueue(queue, p);
           	printf("%c", p->data);
            if(p->left != nullptr) {
            	enQueue(queue, p->left);
            }
            if(p->right != nullptr) {
            	enQueue(queue, p->right);
            }
        }
    }
    
	return 0;
}
