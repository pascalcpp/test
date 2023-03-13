#include<stdio.h>
#include<string.h>
int getIndex(char s[32], int start, int end, char e) {
	for(int i = start; i < end; i++) {
    	if(s[i] == e) {
        	return i;
        }
    }
    return -1;
}

void f(char inorder[32], char postorder[32]
, int s1, int e1, int s2, int e2) {
    if(e1 - s1 == 0) {
        return;
    }

	char rc = postorder[e2-1];
    int idx = getIndex(inorder, s1, e1, rc);
    int m = idx - s1;
    printf("%c", rc);
    f(inorder, postorder, s1, idx, s2, s2+m);
    f(inorder, postorder, idx+1, e1, s2+m, e2-1);
}
int main() {


	char inorder[32];// left root right
    char postorder[32];// left right root
    scanf("%s", inorder);
    scanf("%s", postorder);
    int len = strlen(inorder);
    f(inorder, postorder, 0, len, 0, len);

    return 0;
}
