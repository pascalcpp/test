#include<iostream>
#include<string.h>
using namespace std;
int mat1[1000][1000];
int mat2[1000][1000];
int dis2[1000];
int dis1[1000];
int s[1000];
void dijkstra(int n) {
    for(int i = 0; i < n; i++) {
        dis2[i] = 0x3f3f3f3f;
        dis1[i] = 0x3f3f3f3f;
        s[i] = 0;
    }

    for(int i = 1; i < n; i++) {
        if(mat2[0][i] <= dis2[i]) {
            if(mat2[0][i] == dis2[i]) {
                if(mat1[0][i] < dis1[i]) {
                    dis2[i] = mat2[0][i];
                    dis1[i] = mat1[0][i];
                }
            } else {
                dis2[i] = mat2[0][i];
                dis1[i] = mat1[0][i];
            }
        }
    }
    s[0] = 1;
    for(int i = 1; i < n; i++) {
        int min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f, idx;
        for(int j = 0; j < n; j++) {
            if(!s[j] && dis2[j] <= min2) {
                if(dis2[j] == min2) {
                    if(dis1[j] < min1) {
                        min1 = dis1[j];
                        min2 = dis2[j];
                        idx = j;
                    }
                } else {
                    min1 = dis1[j];
                    min2 = dis2[j];
                    idx = j;
                }
            }
        }

        s[idx] = 1;
        if(idx == n-1) {
            cout << dis2[idx] << " " << dis1[idx] << endl;
            break;
        }

        for(int j = 0; j < n; j++) {
            if(!s[j]) {
                int v1 = dis1[idx] + mat1[idx][j];
                int v2 =  dis2[idx] + mat2[idx][j];
                if(v2 <= dis2[j]) {
                    if(v2 == dis2[j]) {
                        if(v1 < dis1[j]) {
                            dis1[j] = v1;
                            dis2[j] = v2;
                        }
                    } else {
                        dis1[j] = v1;
                        dis2[j] = v2;	
                    }
                }
            }
        }
    }
}
int main() {

    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        memset(mat1, 0x3f, sizeof(mat1));
        memset(mat2, 0x3f, sizeof(mat2));
        for(int i = 0; i < m; i++) {
            int s, e, dis1, dis2;
            cin >> s >> e >> dis1 >> dis2;
            s--;
            e--;
            if(dis2 <= mat2[s][e]) {
                if(mat2[s][e] == dis2) {
                    if(dis1 < mat1[s][e]) {
                        mat2[s][e] = dis2;
                        mat1[s][e] = dis1;
                    }
                } else {
                    mat2[s][e] = dis2;
                    mat1[s][e] = dis1;
                }
            }
        }
        dijkstra(n);
    }
    return 0;
}
