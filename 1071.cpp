#include<stdio.h>
#include<string.h>
#define MAX 10000
typedef struct {
    int edges[MAX][MAX];
    int n;
}MatGraph;
int main() {
    int n, v;
    scanf("%d %d", &n, &v);
    MatGraph* graph = new MatGraph;
    graph->n = n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph->edges[i][j]);
        }
    }
    printf("%d\n", n-1);
    for(int i = 0; i < n; i++) {
        if(i != v) {
            printf("%d", i);
        }
    }
    printf("\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != v && j != v) {
               printf("%d", graph->edges[i][j]);
            }
        }
        if(i != v) {
            printf("\n");
        }
    }
    return 0;
}
