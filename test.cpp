#include<iostream>
#include<cstdlib>
using namespace std;
#define max 50000

struct pos {
    int x;
    int y;
};

typedef struct se
{
    pos data[max];
    int front,rear;
} Sequeue;

void init(Sequeue *&Q)
{
    Q=(Sequeue *)malloc(sizeof(Sequeue));
    Q->front=-1;
    Q->rear=-1;
}

int empty(Sequeue *Q)
{
    if(Q->rear==Q->front)
        return 1;
    else
        return 0;
}

void insertsequeue(Sequeue *&Q,int i,int j)
{
    if((Q->rear+1)%max==Q->front)
    {
        cout<<"队列已满！"<<endl;
        exit(0);
    }
    Q->rear=(Q->rear+1)%max;
    Q->data[Q->rear].x=i;
    Q->data[Q->rear].y=j;
}

void delsequeue(Sequeue *&Q,int &i,int &j)
{
    if(Q->rear==Q->front)
    {
        cout<<"队列已空！"<<endl;
        exit(0);
    }
    Q->front=(Q->front+1)%max;
    i=Q->data[Q->front].x;
    j=Q->data[Q->front].y;
}
int count(int a[50][50],int m,int n)
{
    int v[50][50];
    Sequeue* queue;
    init(queue);
    int c = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            c++;
            if(v[i][j] == 0) {
                insertsequeue(queue, i, j);
                while(!empty(queue)) {
                    int p, q;
                    delsequeue(queue, p, q);

                    if(p-1 >= 0 && v[p-1][q] == 0 && a[p-1][q] != 0) {
                        v[p-1][q] = 1;
                        insertsequeue(queue, p-1, q);
                    }
                    if(q+1 < n && v[p][q+1] == 0 && a[p][q+1] != 0) {
                        v[p][q+1] = 1;
                        insertsequeue(queue, p, q+1);
                    }
                    if(p+1 < m && v[p+1][q] == 0 && a[p+1][q] != 0) {
                        v[p+1][q] = 1;
                        insertsequeue(queue, p+1, q);
                    }
                    if(q-1 >= 0 && v[p][q-1] == 0 && a[p][q-1] != 0) {
                        v[p][q-1] = 1;
                        insertsequeue(queue, p, q-1);
                    }
                }
            }
        }
    }
    return c; //x为计算出在细胞在个数

}

void main()
{
    int test[50][50];
    int i,j, m,n;
    cin>>m;
    cin>>n;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            cin>>test[i][j];

    cout<<count(test,m,n)<<endl;
}
