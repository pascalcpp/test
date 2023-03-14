#include<stdio.h>
#include<stdlib.h>
typedef struct BTNode {
    char data;
    struct BTNode* left;
    struct BTNode* right;
}BTNode, *Btree;
Btree preOrderBuild() {
    char c;
    scanf("%c", &c);
    if(c == '#') {
        return nullptr;
    }
    Btree node = (Btree)malloc(sizeof(BTNode));
    node->data = c;
    node->left = preOrderBuild();
    node->right = preOrderBuild();
    return node;
}
void reverseTree(Btree node) {
	if(node == nullptr) {
    	return;
    }
    reverseTree(node->left);
    reverseTree(node->right);
	Btree t = node->left;
    node->left = node->right;
    node->right = t;
}
void intraverse(Btree node) {
	if(node == nullptr) {
    	return;
    }
    intraverse(node->left);
    printf("%c", node->data);
    intraverse(node->right);
}
void pretraverse(Btree node) {
	if(node == nullptr) {
    	return;
    }
    printf("%c", node->data);
    pretraverse(node->left);
    pretraverse(node->right);
}

int main() {
    Btree root = preOrderBuild();
    reverseTree(root);
    intraverse(root);
    printf("\n");
    pretraverse(root);
    return 0;
}
