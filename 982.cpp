#include<stdio.h>
#include<stdlib.h>
typedef struct BinNode{
	char data;
    BinNode* left;
    BinNode* right;
}BinNode, *Btree;
BinNode* preTraverseBuild() {

    char c;
    scanf("%c", &c);
    if(c == '#') {
    	return nullptr;
    }

    BinNode* node = (BinNode*)malloc(sizeof(BinNode));
    node->data = c;
    node->left = preTraverseBuild();
    node->right = preTraverseBuild();
    return node;
}
void traverse(Btree node, int& max) {
	if(node == nullptr) {
    	return;
    }
    int c = 0;
   	if(node->left != nullptr) {
        c++;
        Btree p = node->left->right;
    	while(p != nullptr) {
            c++;
        	p = p->right;
        }
    }
    if(node->right != nullptr) {
    	c++;
    }

    if(c > max) {
    	max = c;
    }
    traverse(node->left, max);
    traverse(node->right, max);
}
int main() {
    Btree node = preTraverseBuild();
	int max = 0;
    traverse(node, max);
    if(max == 2) {
    	printf("ERROR");
    } else {
    	printf("%d", max);
    }

	return 0;
}
