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
    VNode* vertexs[1000];
}AdjGraph;
int visit[1000];
char id2map[1000];
int map2id[1000];
void dfs(AdjGraph* graph, int v, int level) {
    visit[v] = 1;
    if(level != 0) {
    	printf(" %c", id2map[v]);
    } else {
   		printf("%c", id2map[v]);
    }

    ArcNode* arc = graph->vertexs[v]->firstArc;
    while(arc != nullptr) {
        if(!visit[arc->adjvex]) {
          dfs(graph, arc->adjvex, level+1);
        }
        arc = arc->adjarc;
    }
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
        getchar();
        id2map[i] = c;
        map2id[c-'A'] = i;
    }

    for(int i = 0; i < e; i++) {
        int v1, v2;
        char c1, c2;
        cin >> c1 >> c2;
        //scanf("%c %c", &c1, &c2);
        getchar();
        v1 = map2id[c1-'A'], v2 = map2id[c2-'A'];


        VNode* vec1 = graph->vertexs[v1];
        VNode* vec2 = graph->vertexs[v2];

        if(vec1->firstArc == nullptr) {
            vec1->firstArc = new ArcNode;
            vec1->firstArc->adjvex = v2;
            vec1->firstArc->adjarc = nullptr;
        } else {
            // head insert
            ArcNode* arc = new ArcNode;
            arc->adjvex = v2;
            arc->adjarc = vec1->firstArc;
            vec1->firstArc = arc;
        }

        if(vec2->firstArc == nullptr) {
            vec2->firstArc = new ArcNode;
            vec2->firstArc->adjvex = v1;
            vec2->firstArc->adjarc = nullptr;
        } else {
            ArcNode* arc = new ArcNode;
            arc->adjvex = v1;
            arc->adjarc = vec2->firstArc;
            vec2->firstArc = arc;
        }
    }
    memset(visit, 0x00, sizeof(visit));
    dfs(graph, 0, 0);
	return 0;
}
