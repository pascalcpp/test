#include<stdio.h>
#include<string.h>
#include<deque>
using namespace std;
#define MAX 10000
typedef struct {
    int edges[MAX][MAX];
    int n;
}MatGraph;
int visit[MAX];
deque<int> queue;
void bfs(MatGraph* graph, int i) {
    queue.push_back(i);
    visit[i] = 1;
    while(!queue.empty()) {
        int size = queue.size();
        for (int j = 0; j < size; ++j) {
            int t = queue.front();
            queue.pop_front();
            for(int k = 0; k < graph->n; k++) {
                if(graph->edges[t][k] != 0 && visit[k] == 0) {
                    queue.push_back(k);
                    visit[k] = 1;
                }
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    MatGraph* graph = new MatGraph;
    graph->n = n;
    memset(visit, 0, sizeof(visit));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph->edges[i][j]);
        }
    }
    int c = 0;
    for(int i = 0; i < n; i++) {
        if(visit[i] == 0) {
            c++;
            bfs(graph, i);
        }
    }
    printf("%d", c);



    return 0;
}
