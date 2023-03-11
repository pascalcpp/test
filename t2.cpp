#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
#define max 50000


typedef struct
{
    int data[max];
    int size;
    int front,rear;
} Sequeue;

void init(Sequeue *&Q)
{
    Q=(Sequeue *)malloc(sizeof(Sequeue));
    Q->front=0;
    Q->rear=0;
}

int empty(Sequeue *Q)
{
    if(Q->rear==Q->front)
        return 1;
    else
        return 0;
}

void insertsequeue(Sequeue *&Q,int e)
{
    if((Q->rear+1)%size==Q->front)
    {
        cout<<"队列已满！"<<endl;
        exit(0);
    }
    Q->rear=(Q->rear+1)%size;
    Q->data[Q->rear] = e;
}

void delsequeue(Sequeue *&Q,int& e)
{
    if(Q->rear==Q->front)
    {
        cout<<"队列已空！"<<endl;
        exit(0);
    }
    Q->front=(Q->front+1)%size;
   	e = Q->data[Q->front];
}

int main()
{
   	int n, k;
    scanf("%d%d", &n, &k);
    getchar();
    Sequeue * Q;
   	for(int i = 0; i < k; i++) {
    	char s[16];
        int e;
        scanf("%s", s);
        if(strcmp(s, "in") == 0) {
            scanf("%d", &e);
        	insertsequeue(Q, e);
        } else {
        	delsequeue(Q, e);
        }       
    }
    int e;
    if(!empty(Q)){
    	delsequeue(Q, e);
        printf("%d", e);
    }
    
    while(!empty(Q)) {
    	
        delsequeue(Q, e);
        printf(" %d", e);
        
    }
	
    return 0;
}
