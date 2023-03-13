#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct haffNode {
    char data;
    int weight;
    struct haffNode* left, *right;
}haffNode, *hafftree;

void msort(hafftree nodes[100], int len) {
    for(int i = 0; i < len-1; i++) {
        int maxi = i;
        for(int j = i+1; j < len; j++) {
            if(nodes[j]->weight >= nodes[maxi]->weight) {
                maxi = j;
            }
        }
        hafftree p = nodes[maxi];
        nodes[maxi] = nodes[i];
        nodes[i] = p;
    }
}
void traverse(hafftree node, char a[128], int& len, char* ans[1000]) {
    if(node == nullptr) {
        return;
    }

    if(node->left == nullptr && node->right == nullptr) {
        char* s = (char*)malloc(len);
        a[len] = '\0';
        memcpy(s, a, len+1);
        ans[node->data] = s;
    }
    if(node->left != nullptr) {
        a[len++] = '0';
        traverse(node->left, a, len, ans);
        len--;
    }

    if(node->right != nullptr) {
        a[len++] = '1';
        traverse(node->right, a, len, ans);
        len--;
    }

}
int main() {
    hafftree nodes[100];
    int n;
    scanf("%d", &n);
    char res[128];
    getchar();
    for(int i = 0; i < n; i++) {
        nodes[i] = (hafftree)malloc(sizeof(haffNode));
        scanf("%c", &nodes[i]->data);
        res[i] = nodes[i]->data;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &nodes[i]->weight);
        nodes[i]->left = nullptr;
        nodes[i]->right = nullptr;
    }
    int len = n;
    for(int i = 0; i < n-1; i++) {
        msort(nodes, len);
        hafftree p = (hafftree)malloc(sizeof(haffNode));
        p->weight = nodes[len-2]->weight+nodes[len-1]->weight;
        p->left = nodes[len-1];
        p->right = nodes[len-2];
        len--;
        nodes[len-1] = p;
    }
    char a[128] = "";
    char* ans[1000];
    int le = 0;
    traverse(nodes[0], a, le, ans);
    for(int i = 0; i < n; i++) {
        printf("%s", ans[res[i]]);
        if(i != n-1) {
        	printf("\n");
        }
    }

    return 0;
}
