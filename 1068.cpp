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
void dfs(MatGraph* graph, int v) {
	visit[v] = 1;
    printf("%c", id2map[v]);
    for(int i = 0; i < graph->n; i++) {
    	if(!visit[i] && graph->edges[v][i] > 0) {
        	dfs(graph, i);
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
    dfs(graph, map2id[c-'A']);
    return 0;
}
