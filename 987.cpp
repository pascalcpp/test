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
int traverse(Btree node) {
	if(node == nullptr) {
    	return 1;
    }
    if(node->left == nullptr && node->right != nullptr) {
    	return 0;
    }
    if(node->left != nullptr && node->right != nullptr) {
    	if(node->left->right == nullptr && node->right->left != nullptr) {
        	return 0;
        }
    }
    if(!traverse(node->left)) {
    	return 0;
    }
    return traverse(node->right);

}

int main() {
	Btree root = preOrderBuild();
    int f = traverse(root);
    if(f) {
    	printf("Y");
    } else {
    	printf("N");
    }
    return 0;
}
