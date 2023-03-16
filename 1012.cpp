#include<stdio.h>
#include<string.h>
#define MAX 10000
typedef struct Node {
	int data;
    struct Node* next;
}Node;
int main() {
	int m, n, val;
    Node* hashmap[MAX];
    memset(hashmap, 0, sizeof(hashmap));
    scanf("%d", &m);
	scanf("%d", &n);
    for(int i = 0; i < n; i++) {
    	int temp;
        scanf("%d", &temp);
        Node* node = new Node;
        node->data = temp;
        node->next = nullptr;
        int hash = temp%m;
        if(hashmap[hash] != nullptr) {
        	Node* cur = hashmap[hash];
            while(cur->next != nullptr) {
            	cur = cur->next;
            }
            cur->next = node;
        } else {
        	hashmap[hash] = node;
        }
    }
    scanf("%d", &val);
    int hash = val%m;
    Node* cur = hashmap[hash];
    int c = 0;
    while(cur != nullptr && cur->data != val) {
        c++;
        cur = cur->next;
    }
    if(cur == nullptr) {
    	printf("-1");
    } else {
    	printf("%d,%d", hash, c+1);
    }

	return 0;
}
