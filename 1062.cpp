#include<stdio.h>
#define MAX 10000
typedef struct {
    int edges[MAX][MAX];
    int outdegrees[MAX];
    int n;
}MatGraph;

int main() {
    int n;
    scanf("%d", &n);
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    MatGraph* graph = new MatGraph;
    graph->n = n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph->edges[i][j]);
        }
    }
    if(graph->edges[v1][v2] == 1) {
        printf("yes");
    } else {
        printf("no");
    }


    return 0;
}
