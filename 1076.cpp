#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
typedef struct ANode{
	int adjvex;
    ANode* adjarc;
}ArcNode;
typedef struct VVNode {
	int val;
    ArcNode* firstArc;
}VNode;
typedef struct Graph{
	int n;
	int e;
    VNode* vertexs[10000];
}AdjGraph;
int visit[10000];
char id2map[10000];
int map2id[10000];
int dfs(AdjGraph* graph, int v) {
    visit[v] = 1;
    ArcNode* arc = graph->vertexs[v]->firstArc;
    while(arc != nullptr) {
        if(visit[arc->adjvex]) {
            return -1;
        } else {
            if(dfs(graph, arc->adjvex) == -1) {
                return -1;
            }
        }
        visit[arc->adjvex] = 0;
        arc = arc->adjarc;
    }
    return 1;
}
int main(){
    int n, e;
    scanf("%d%d", &n, &e);
    AdjGraph* graph = new AdjGraph;
    graph->n = n;
    graph->e = e;
    for(int i = 0; i < n; i++) {
        graph->vertexs[i] = new VNode;
        graph->vertexs[i]->val = i;
        graph->vertexs[i]->firstArc = nullptr;
    }
    getchar();
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c; 
        // scanf("%c", &c);
        getchar();
        id2map[i] = c;
        map2id[c-'A'] = i;
    }

    for(int i = 0; i < e; i++) {
        int v1, v2;
        char c1, c2;
        cin >> c1 >> c2;
        // scanf("%c %c", &c1, &c2);
        getchar();
        v1 = map2id[c1-'A'], v2 = map2id[c2-'A'];


        VNode* vec = graph->vertexs[v1];

        if(vec->firstArc == nullptr) {
            vec->firstArc = new ArcNode;
            vec->firstArc->adjvex = v2;
            vec->firstArc->adjarc = nullptr;
        } else {
            // head insert

            ArcNode* arc = vec->firstArc;
            while(arc->adjarc != nullptr) {
                arc = arc->adjarc;
            }
            arc->adjarc = new ArcNode;
            arc->adjarc->adjarc = nullptr;
            arc->adjarc->adjvex = v2;
        }

    }

    for(int i = 0; i < n; i++) {
        memset(visit, 0x00, sizeof(visit));
        if(dfs(graph, i) == -1) {
            printf("yes");
            return 0;
        }
    }
    printf("no");
	return 0;
}
