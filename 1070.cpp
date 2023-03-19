#include<stdio.h>
#include<string.h>
#define MAX 10000
typedef struct {
    int edges[MAX][MAX];
    int n;
}MatGraph;
int visit[MAX];
int path[MAX];
void dfs(MatGraph* graph, int s, int e, int start) {
    visit[s] = 1;

    if(s == e) {
        int k = start;
        while(path[k] != k) {
            printf("%d", k);
            k = path[k];
        }
        printf("%d\n", k);
        return;
    }
    for(int i = 0; i < graph->n; i++) {
        if(!visit[i] && graph->edges[s][i] > 0) {
            path[s] = i;
            dfs(graph, i, e, start);
            visit[i] = 0;
        }
    }

}
int main() {
    int n;
    scanf("%d", &n);
    MatGraph* graph = new MatGraph;
    graph->n = n;
    int s, e;
    scanf("%d %d", &s, &e);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph->edges[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        path[i] = i;
    }
    memset(visit, 0x00, sizeof(visit));
    dfs(graph, s, e, s);
    return 0;
}
