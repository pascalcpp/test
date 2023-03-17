#include<stdio.h>
#include<math.h>
int arr[10000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
    	scanf("%d", &arr[i]);
    }
	// shell sort;
    // d = 5
    int d = n/2;
    while(d > 0) {
    	for(int i = d; i < n; i++) {
            for(int j = i; j < n; j+=d) {
            	int temp = arr[j];
                int val = j;
                while(j >= d && arr[j-d] > arr[j]) {
                	arr[j] = arr[j-d];
                    j -= d;
                }
                arr[j] = temp;
                j = val;
            }
        }
        break;
        d /= 2;
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
	return 0;
}
