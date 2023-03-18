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
    VNode* vertexs[100];
}AdjGraph;
int main(){
    int n;
    scanf("%d", &n);
    getchar();
    AdjGraph* graph = new AdjGraph;
    graph->n = n;
    for(int i = 0; i < n; i++) {
    	char c = getchar();
        VNode* node;
        node->val = i;
        node->firstArc = nullptr;
        graph->vertexs[i] = node;
        ArcNode* arc;
        if(c == '\n') {            
        	continue;
        }else {
        	arc = new ArcNode;
            arc->adjvex = c-'0';
            arc->adjarc = nullptr;
        }
        node->firstArc = arc;
       	while(getchar() != '\n') {
        	char e = getchar();
           	arc->adjarc = new ArcNode;
            arc->adjarc->adjarc = nullptr;
            arc->adjvex = e-'0';
            arc = arc->adjarc;
        }
    }
    for(int i = 0; i < n; i++) {
    	ArcNode* arc = graph->vertexs[i]->firstArc;
        
        for(int j = 0; j < n; j++) {
        	if(arc != nullptr && arc->adjvex == j) {
            	printf("1");
            } else {
            	printf("0");
            }
        }
        printf("\n");
    }
	return 0;
}
