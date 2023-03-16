#include<stdio.h>
typedef struct BNode{
    int data;
    struct BNode* left;
    struct BNode* right;
}BNode, *Btree;
Btree buildNode(int e);
void insert(Btree root, int e) {
	if(root == nullptr) {
    	return;
    }
    if(root->data < e) {
    	if(root->right == nullptr) {
        	root->right = buildNode(e);
        } else {
        	insert(root->right, e);
        }

    } else {
        if(root->left == nullptr) {
            root->left = buildNode(e);
        } else {
        	insert(root->left, e);
        }
    }
}
int search(Btree root, int val, int c) {
	if(root == nullptr) {
    	return -1;
    }
    if(root->data == val) {
    	return c+1;
    } else if(root->data < val) {
    	return search(root->right, val, c+1);
    } else {
    	return search(root->left, val, c+1);
    }

}
Btree buildNode(int e) {
	Btree node = new BNode;
    node->data = e;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
int main() {
	Btree root;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
    	int temp;
        scanf("%d", &temp);
        if(i == 0) {
        	root = buildNode(temp);
        } else {
        	insert(root, temp);
        }
    }
    int val;
    scanf("%d", &val);
    printf("%d", search(root, val, 0));
	return 0;
}
