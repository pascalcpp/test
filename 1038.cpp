#include<stdio.h>
#include<string.h>
#define MAX 100000
typedef struct {
    int data[MAX];
    int len;
}Array;
int main() {
    Array list;
    list.len = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &list.data[list.len++]);
    }
    int val;
    scanf("%d", &val);
    for(int i = 0; i < list.len;) {
        if(list.data[i] == val) {
            for(int j = i+1; j < list.len; j++) {
                list.data[j-1] = list.data[j];
            }
            list.len--;
        } else {
            i++;
        }
    }
    if(list.len == 0) {
        printf("-1");
    } else {
        for(int i = 0; i < list.len; i++) {
            printf("%d ", list.data[i]);
        }
    }

    return 0;
}
