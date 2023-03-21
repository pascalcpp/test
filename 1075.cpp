#include<iostream>
using namespace std;

typedef struct
{
    int n;
    int e;
    char data[500];
    int edge[500][500];
}Graph;

typedef struct
{
    int index;
    int cost;
}mincost;

typedef struct
{
    int x;
    int y;
    int weight;
}EDGE;


typedef struct
{
    int index;
    int flag;
}F;

void create(Graph &G,int n ,int e)
{
    int i,j,k,w;
    char a,b;
    for(i=0;i< n;i++)
        cin>>G.data[i];
    for(i=0;i< n;i++)
        for(j=0;j< n;j++)
        {
            if(i==j)
                G.edge[i][j]=0;
            else
                G.edge[i][j]=100;
        }

    for(k=0;k< e;k++)
    {
        cin>>a;
        cin>>b;
        cin>>w;
        for(i=0;i< n;i++)
            if(G.data[i]==a) break;
        for(j=0;j< n;j++)
            if(G.data[j]==b) break;

        G.edge[i][j]=w;
        G.edge[j][i]=w;
    }
    G.n=n;
    G.e=e;
}
int closest[500];
int lowcost[500];
void Prim(Graph &G,int k)
{

    for(int i = 0; i < G.n; i++) {
    	closest[i] = k;
    }
	for(int i = 0; i < G.n; i++) {
    	// k -> i
        lowcost[i] = G.edge[k][i];
    }
    for(int i = 1; i < G.n; i++) {
    	int min = 100;
        int v;
        for(int j = 0; j < G.n; j++) {
        	if(lowcost[j] > 0 && lowcost[j] < min) {
            	min = lowcost[j];
                v = j;
            }
        }
        printf("(%c,%c)", G.data[closest[v]], G.data[v]);
      	lowcost[v] = 0;
        for(int j = 0; j < G.n; j++) {
            // V-U vertexs
      		if(lowcost[j] > 0 && G.edge[v][j] > 0 && G.edge[v][j] < lowcost[j]) {
                lowcost[j] = G.edge[v][j];
            	closest[j] = v;
            }
        }
    }


    //完成Prim算法

}

int main()
{
    Graph my;
    int n,e;
    cin>>n>>e;
    create(my,n,e);
    Prim(my,0);
    return 0;
}
