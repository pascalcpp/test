#include<stdio.h>
#define MAX 10000
typedef struct {
    int edges[MAX][MAX];
    int outdegrees[MAX];
    int n;
}MatGraph;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    MatGraph* graph = new MatGraph;
    graph->n = n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph->edges[i][j]);
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int c = 0;
        for(int j = 0; j < n; j++) {
            if(graph->edges[i][j] == 1) {
                c++;
            }
        }
        graph->outdegrees[i] = c;
        if(c == k) {
            sum++;
        }
    }
    printf("%d\n", sum);
    for(int i = 0; i < n; i++) {
        if(graph->outdegrees[i] == k) {
            printf("%d", i);
        }
    }

    return 0;
}
