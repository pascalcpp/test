#include<iostream>
#include<algorithm>
#define MAX 50000
using namespace std;
int nums[MAX];
//         i                       j
int partition(int arr[], int start, int end) {
	int i = start, j = end;
    int temp = arr[i];
    while(i<j) {
    	while(i<j && arr[j] >= temp) {
        	j--;
        }
        arr[i] = arr[j];
        
        while(i<j && arr[i] <= temp) {
        	i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = temp;
    return i;
}
void quicksort(int arr[], int start, int end) {
    if(end-start < 1) {
    	return;
    }
    int pivot = partition(arr, start, end);
    quicksort(arr, start, pivot-1);
    quicksort(arr, pivot+1, end);
}
int main() {
	int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
    	cin >> nums[i];
    }
    quicksort(nums, 0, n-1);
    for(int i = 0; i < n; i++) {
    	cout << nums[i] << " ";
    }
    cout << endl;
	return 0;
}
