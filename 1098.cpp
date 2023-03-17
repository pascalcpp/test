#include<stdio.h>
#include<math.h>
int arr[10000];
bool traverse(int arr[], int n, int k, int limit) {
	if(k > limit) {
    	return true;
    }
    int l = k*2+1;
    int r = k*2+2;
    if(arr[k] <= arr[l]) {
        if(r <= n) {
        	if(arr[k] <= arr[r]) {
            return traverse(arr, n, l, limit) && traverse(arr, n, r, limit);
            } else {
            	return false;
            }
        } else {
        	return true;
        }
    } else {
    	return false;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
    	scanf("%d", &arr[i]);
    }
	if(traverse(arr, n-1, 0, n/2-1)){
    	printf("Yes");
    } else {
    	printf("No");
    }
	return 0;
}
