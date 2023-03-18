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
void bfs(MatGraph* graph, int i, int& c) {
    queue.push_back(i);
    visit[i] = 1;
    c++;
    while(!queue.empty()) {
        int size = queue.size();
        for (int j = 0; j < size; ++j) {
            int t = queue.front();
            queue.pop_front();
            for(int k = 0; k < graph->n; k++) {
                if(graph->edges[t][k] != 0 && visit[k] == 0) {
                    queue.push_back(k);
                    c++;
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
    for(int i = 0; i < n; i++) {
        memset(visit, 0, sizeof(visit));
        int c = 0;
      // 判断是否每个点是否都能到其他点， 在有向图中， 必须对所有点都判断， 因为 i能到j j不一定能到i
        bfs(graph, i, c);
        if(c != n) {
            printf("no");
            return 0;
        }
    }
    printf("yes");



    return 0;
}
