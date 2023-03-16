#include<stdio.h>
typedef struct{
	int data[10000];
	int len;
}Sqlist;

void init(Sqlist *& list){
	list = new Sqlist;
    list->len = 0;
}
void insertFirst(Sqlist *& list, int e) {
	for(int i = list->len-1; i >= 0; i--) {
    	list->data[i+1] = list->data[i];
    }
    list->data[0] = e;
    list->len++;
}

void remove(Sqlist *& list, int k) {
	for(int i = k+1; i < list->len; i++) {
    	list->data[i-1] = list->data[i];
    }
    list->len--;
}
int main() {
    Sqlist* list;
    init(list);
	int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
    	scanf("%d", &list->data[list->len++]);
    }
   	int s, e;
    scanf("%d %d", &s, &e);
    for(int i = 0; i < list->len;) {
		if(list->data[i] >= s && list->data[i] <= e) {
        	remove(list, i);
        } else {
        	i++;
        }
    }

    //

    for(int i = 0; i < list->len; i++) {
        printf("%d ", list->data[i]);
    }
	return 0;
}
