#include<stdio.h>
typedef struct{
	int data[10000];
	int len;
}Sqlist;

void init(Sqlist *& list){
	list = new Sqlist;
    list->len = 0;
}

int main() {
    Sqlist* list;
    init(list);
    Sqlist* ans;
    init(ans);
	int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
    	scanf("%d", &list->data[list->len++]);
    }
    int p;

    scanf("%d", &p);
    // 0 1 2 3
    if(p < 0 || p >= n) {
    	printf("error!");
    } else {
        ans->len = list->len;
    	for(int i = 0; i < n; i++) {
            //
            ans->data[i] = list->data[(p+i)%n];
        }
		// 1 2 3 4 5 6 7 8 9 10
        // 10 1 2 3 4 5 6 7 8 9

        for(int i = 0; i < n; i++) {
            printf("%d ", ans->data[i]);
        }
    }
	return 0;
}
