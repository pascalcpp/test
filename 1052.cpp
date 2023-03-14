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
int traverseFind(Btree node, char& ch) {
	if(node == nullptr) {
    	return 0;
    }

    if(node->left != nullptr && node->left->data == ch) {
        printf("%c", node->data);
        return 1;
    }

    if(node->right != nullptr && node->right->data == ch) {
        printf("%c", node->data);
		return 1;
    }


    if(traverseFind(node->left, ch)) {
    	return 1;
    }
    if(traverseFind(node->right, ch)) {
        return 1;
    }
    return 0;

}

int main() {
	Btree root = preOrderBuild();
	char temp = getchar();
	char ch;
    scanf("%c", &ch);
    if(root->data == ch) {
    	printf("#");
    } else {
    	traverseFind(root, ch);
    }


    return 0;
}
