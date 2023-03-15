#include<stdio.h>
#include<string.h>
#define MAX 100000
typedef struct{
	int data[MAX];
	int len;
}SqList;
int map[MAX];
void init(SqList *& list){
	list = new SqList;
    list->len = 0;
}
int main() {
    SqList *la, *lb, *res;
    init(la);
    init(lb);
    init(res);
    memset(map, 0x00, sizeof(map));
    int n1, n2;
    scanf("%d", &n1);
    for(int i = 0; i < n1; i++) {
    	int t;
        scanf("%d", &t);
        la->data[la->len++] = t;
    }
    scanf("%d", &n2);
    for(int i = 0; i < n2; i++) {
    	int t;
        scanf("%d", &t);
        map[t]++;
        lb->data[lb->len++] = t;
    }
    for(int i = 0; i < n1; i++) {
    	if(map[la->data[i]] != 0) {
        	res->data[res->len++] = la->data[i];
        }
    }
    for(int i = 0; i < res->len; i++) {
    	printf("%d ", res->data[i]);
    }
	return 0;
}
