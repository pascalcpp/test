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
    if(node->data == ch) {
        int c = 0;
        if(node->left != nullptr) {
            c++;
        }
        if(node->right != nullptr) {
            c++;
        }
        printf("%d", c);
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

        traverseFind(root, ch);



    return 0;
}
