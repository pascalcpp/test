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
    int val;
    scanf("%d", &val);
    int s = 0, e = n-1;
    int c = 0;
    int mid;
    while(s <= e) {
    	mid = (s+e)>>1;
        c++;
        if(list->data[mid] < val) {
        	s = mid+1;
        } else if(list->data[mid] > val) {
            e = mid-1;
        } else {
            break;
        }
    }
    if(list->data[mid] != val) {
    	printf("-1");
    } else {
    	printf("%d", mid);
    }
    printf("\n%d", c);
	return 0;
}
