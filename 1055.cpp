#include<stdio.h>
typedef struct Graph{
	int arr[1000][1000];
}Matrix;
Matrix mat; // avoid stack overflow
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
        	scanf("%d", &mat.arr[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < n; j++) {
        	if(mat.arr[i][j] == 1) {
            	printf("%d", j);
            }
        }
        printf("\n");
    }
	return 0;
}
