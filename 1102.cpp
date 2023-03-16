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
    int pivot = list->data[0];
    for(int i = 1; i < n; i++) {
    	int e = list->data[i];
        if(e <= pivot) {
        	remove(list, i);
            insertFirst(list, e);
        }
    }

    //
    //int i = 0, j = n-1;
//    while(i < j) {
//        int temp;
//    	while(i < j && list->data[j] > list->data[i]) {
//        	j--;
//        }
//        temp = list->data[i];
//        list->data[i] = list->data[j];
//        list->data[j] = temp;
//        while(i < j && list->data[i] <= list->data[j]) {
//        	i++;
//        }
//        temp = list->data[i];
//        list->data[i] = list->data[j];
//        list->data[j] = temp;
//    }
    for(int i = 0; i < n; i++) {
        printf("%d ", list->data[i]);
    }
	return 0;
}
