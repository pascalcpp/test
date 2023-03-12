#include<stdio.h>
#include<stdlib.h>
typedef struct BinNode{
	char data;
    BinNode* left;
    BinNode* right;
}BinNode;
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
void traverse(BinNode* node, int &sum) {
	if(node == nullptr) {
    	return;
    }

    int c = 0;
    if(node->left != nullptr) {
        c++;
    	traverse(node->left, sum);
    }

    if(node->right != nullptr) {
        c++;
		traverse(node->right, sum);
    }
    if(c == 1) {
    	sum++;
    }
}
int main() {
    BinNode* node = preTraverseBuild();
    int sum = 0;
    traverse(node, sum);
    printf("%d", sum);
	return 0;
}
