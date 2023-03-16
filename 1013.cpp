#include<stdio.h>
#include<string.h>
#define MAX 10000
int main() {
	int m, n, val;
    int hashmap[MAX];
    memset(hashmap, 0x3f, sizeof(hashmap));
    scanf("%d", &m);
	scanf("%d", &n);
    for(int i = 0; i < n; i++) {
    	int temp;
        scanf("%d", &temp);
        int hash = temp%m;
        if(hashmap[hash] != 0x3f3f3f3f) {
            while(hashmap[hash] != 0x3f3f3f3f) {
            	hash = (hash+1)%m;
            }
            hashmap[hash] = temp;
        } else {
        	hashmap[hash] = temp;
        }
    }
    scanf("%d", &val);
    int hash = val%m;
    int c = 0;
    // 0 1 2 3 4
    while(c < m && hashmap[hash] != val) {
        c++;
        hash = (hash+1)%m;
    }
    if(c == m) {
    	printf("-1");
    } else {
    	printf("%d,%d", hash, c+1);
    }

	return 0;
}
