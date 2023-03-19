#include<stdio.h>
#include<string.h>
#define MAX 10000
typedef struct {
    int edges[MAX][MAX];
    int n;
}MatGraph;
int visit[MAX];
void dfs(MatGraph* graph, int s, int& c) {
    visit[s] = 1;
    c++;
    for(int i = 0; i < graph->n; i++) {
        if(!visit[i] && graph->edges[s][i] > 0) {
            dfs(graph, i, c);
        }
    }

}
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
        memset(visit, 0x00, sizeof(visit));
        dfs(graph, i, c);
        if(c == n) {
            printf("%d", i);
        }
    }

    return 0;
}
