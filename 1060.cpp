#include<stdio.h>
#define MAX 10000
typedef struct {
    int edges[MAX][MAX];
    int degrees[MAX];
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
    int maxd = 0;
    for(int i = 0; i < n; i++) {
        int c = 0;
        for(int j = 0; j < n; j++) {
            if(graph->edges[i][j] == 1) {
                c++;
            }
        }
        graph->degrees[i] = c;
        if(c > maxd) {
            maxd = c;
        }
    }
    printf("%d\n", maxd);
    for(int i = 0; i < n; i++) {
        if(graph->degrees[i] == maxd) {
            printf("%d", i);
        }
    }

    return 0;
}
