#include<stdio.h>
#define MAX 10000
typedef struct {
    int edges[MAX][MAX];
    int n;
}MatGraph;

int main() {
    int n;
    scanf("%d", &n);
    MatGraph* graph = new MatGraph;
    graph->n = n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph->edges[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        int c = 0;
        for(int j = 0; j < n; j++) {
            if(graph->edges[i][j] == 1) {
                c++;
            }
        }
        printf("%d\n", c);
    }
    return 0;
}
