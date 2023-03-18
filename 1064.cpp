#include<stdio.h>
#define MAX 10000
typedef struct {
    int edges[MAX][MAX];
    int outdegrees[MAX];
    int n;
}MatGraph;
typedef struct {
    int v1, v2;
}Edge;
Edge minEdge[MAX], maxEdge[MAX];
int main() {
    int n;
    scanf("%d", &n);
    MatGraph* graph = new MatGraph;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph->edges[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(graph->edges[i][j] != graph->edges[j][i]) {
                printf("no");
                return 0;
            }
        }
    }
    printf("yes");


    return 0;
}
