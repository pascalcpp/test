#include<iostream>
using namespace std;
int arr[1000];
int main() {
	int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    int val, c = 0, idx = -1;
    cin >> val;
    for(int i = 0; i < n; i++) {
    	if(val == arr[i]) {
        	c++;
            idx = -1;
           	break;
        } else {
        	c++;
        }
    }
    cout << idx << endl << c;



	return 0;
}
