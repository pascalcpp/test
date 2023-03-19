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
    VNode* vertexs[10000];
}AdjGraph;
int ans[10000];
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
    int len = 0, maxdegree = 0;;
    for(int i = 0; i < n; i++) {
        ArcNode* arc = graph->vertexs[i]->firstArc;
        int degree = 0;
        while(arc != nullptr) {
            degree++;
            arc = arc->adjarc;
        }
        if(degree > maxdegree){
        	maxdegree = degree;
            len = 0;
            ans[len++] = i;
        }else if(degree == maxdegree) {
        	ans[len++] = i;
        }
    }
    printf("%d\n", maxdegree);
    for(int i = 0; i < len; i++) {
    	printf("%d", ans[i]);
    }
	return 0;
}
