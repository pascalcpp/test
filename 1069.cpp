#include<stdio.h>
#include<string.h>
#define MAX 10000
typedef struct {
    int edges[MAX][MAX];
    int n;
}MatGraph;
int visit[MAX];
char id2map[MAX];
int map2id[50];
int queue[MAX];
int rear = 0, front = 0;
void push(int e) {
    if((rear+1)%MAX == front) {
        return;
    }
    rear = (rear+1)%MAX;
    queue[rear] = e;
}
void pop(int& e) {
    if(rear == front) {
        return;
    }
    front = (front+1)%MAX;
    e = queue[front];
}
void bfs(MatGraph* graph, int v) {
	visit[v] = 1;
    push(v);
    while(rear != front) {
        int e;
        pop(e);
        printf("%c", id2map[e]);
        for(int i = 0; i < graph->n; i++) {
            if(!visit[i] && graph->edges[e][i] > 0) {
                visit[i] = 1;
                push(i);
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    MatGraph* graph = new MatGraph;
    graph->n = n;
    getchar();
    for(int i = 0; i < n; i++) {
    	scanf("%c", &id2map[i]);
       	map2id[id2map[i]-'A'] = i;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph->edges[i][j]);
        }
    }
    char c;
    getchar();
    scanf("%c", &c);
    memset(visit, 0x00, sizeof(visit));
    bfs(graph, map2id[c-'A']);
    return 0;
}
