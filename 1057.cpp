#include<stdio.h>
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
    VNode* vertexs[100];
}AdjGraph;
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

    for(int i = 0; i < e; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        VNode* vec = graph->vertexs[v1];
        if(vec->firstArc == nullptr) {
            vec->firstArc = new ArcNode;
            vec->firstArc->adjvex = v2;
            vec->firstArc->adjarc = nullptr;
        } else {
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
        ArcNode* arc = graph->vertexs[i]->firstArc;
        int degree = 0;
        while(arc != nullptr) {
            degree++;
            arc = arc->adjarc;
        }
        printf("%d\n", degree);
    }
	return 0;
}
