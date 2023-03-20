#include<iostream>
#include<string.h>
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
int uset[128];
int visit[128];
EDGE edges[256];
void Prim(Graph &G,int k)
{
    memset(visit, 0x00, sizeof(visit));
    int nu = 0, ne = 0;
    uset[nu++] = k;
    visit[k] = 1;
    for(int i = 0; i < G.n-1; i++) {
        mincost mc;
        mc.cost = 100;
        int end;
        for(int j = 0; j < nu; j++) {
        	for(int p = 0; p < G.n; p++) {
            	if((G.edge[uset[j]][p] > 0 && G.edge[uset[j]][p] < 100) &&
                  !visit[p] && G.edge[uset[j]][p] < mc.cost) {
               		mc.cost = G.edge[uset[j]][p];
                    mc.index = uset[j];
                    end = p;
                }
            }
        }
        visit[end] = 1;
        uset[nu++] = end;
       	edges[ne].x = mc.index, edges[ne].y = end;
        edges[ne].weight = mc.cost;
        ne++;
    }
    for(int i = 0; i < ne; i++) {
    	printf("(%c,%c)", G.data[edges[i].x], G.data[edges[i].y]);
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
