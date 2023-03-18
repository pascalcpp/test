#include <iostream>
using namespace std;

// 查找成功返回该元素的index, 失败返回-1
int seq_search(const int seq[], int n, const int &value, int& c) {
    for(int i = 0; i < n; i++) {
        if(seq[i] == value) {
            c++;
            return i;
        }
        c++;
    }

    return -1;
}
int arr[1000000];
int main() {
	int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    int val, c = 0;
    cin >> val;
    int idx = seq_search(arr, n, val, c);
    if(idx == -1) {
    	cout << idx << "\r\n" << c;
    } else {
	    // 位序 = 下标+1
    	cout << idx+1 << "\r\n" << c;
    }


    return 0;
}
