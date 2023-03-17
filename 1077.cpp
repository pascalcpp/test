#include<stdio.h>
#include<math.h>
typedef struct BNode {
    char data;
	struct BNode* left;
    struct BNode* right;
}BNode, *Btree;
Btree prebuild() {
	char c;
    scanf("%c", &c);
    if(c == '#') {
    	return nullptr;
    }
    Btree node = new BNode;
    node->data = c;
    node->left = prebuild();
    node->right = prebuild();
    return node;
}
int height(Btree root, int high) {
	if(root == nullptr) {
    	return 0;
    }
    int l = height(root->left, high)+1;
    int r = height(root->right, high)+1;
    return l > r ? l : r;
}
bool balance(Btree root) {
    int l = height(root->left, 0);
    int r = height(root->right, 0);
    if(abs(l-r) <= 1) {
    	return true;
    }
    return false;
}

bool isbalance(Btree root) {
    if(root == nullptr) {
    	return true;
    }
    if(isbalance(root->left) && isbalance(root->right)) {
    	return balance(root);
    }
    return false;
}



int main() {
	Btree root = prebuild();
    if(isbalance(root)) {
    	printf("yes!");
    } else {
    	printf("no!");
    }
	return 0;
}
