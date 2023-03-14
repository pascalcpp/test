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
int traverse(Btree node, char& ch) {
	if(node == nullptr) {
    	return 0;
    }
    if(node->data == ch) {
    	if(node->left == nullptr) {
        	printf("L:#,");
        } else {
        	printf("L:%c,", node->left->data);
        }
        if(node->right == nullptr) {
            printf("R:#");
        } else {
			printf("R:%c", node->right->data);
        }
        return 1;
    }
    if(traverse(node->left, ch)) {
    	return 1;
    }
    if(traverse(node->right, ch)) {
        return 1;
    }
    return 0;

}

int main() {
	Btree root = preOrderBuild();
	char temp = getchar();
	char ch;
    scanf("%c", &ch);
    traverse(root, ch);

    return 0;
}
