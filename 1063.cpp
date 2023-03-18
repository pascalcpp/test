#include<stdio.h>
#define MAX 10000
typedef struct {
    int edges[MAX][MAX];
    int outdegrees[MAX];
    int n;
}MatGraph;
typedef struct {
    int v1, v2;
}Edge;
Edge minEdge[MAX], maxEdge[MAX];
int main() {
    int n, k1 = 0, k2 = 0;
    scanf("%d", &n);
    MatGraph* graph = new MatGraph;
    int max = 0, min = 0x3f3f3f3f;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int t;
            scanf("%d", &t);
            graph->edges[i][j] = t;
            if(t > 0) {
                if(t > max) {
                    max = t;
                    k1 = 0;
                    maxEdge[k1].v1 = i;
                    maxEdge[k1].v2 = j;
                    k1++;
                } else if(t == max) {
                    maxEdge[k1].v1 = i;
                    maxEdge[k1].v2 = j;
                    k1++;
                }

                if(t < min) {
                    min = t;
                    k2 = 0;
                    minEdge[k2].v1 = i;
                    minEdge[k2].v2 = j;
                    k2++;
                } else if(t == min) {
                    minEdge[k2].v1 = i;
                    minEdge[k2].v2 = j;
                    k2++;
                }
            }
        }
    }
    printf("%d\n", max);
    for(int i = 0; i < k1; i++) {
        printf("<%d %d>", maxEdge[i].v1,  maxEdge[i].v2);
    }
    printf("\n%d\n", min);
    for(int i = 0; i < k2; i++) {
        printf("<%d %d>", minEdge[i].v1,  minEdge[i].v2);
    }

    return 0;
}
