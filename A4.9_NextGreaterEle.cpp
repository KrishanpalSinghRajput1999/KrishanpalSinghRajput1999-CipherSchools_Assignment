#include<bits/stdc++.h>
using namespace std;
void findnextgreater(int arr[], int n) {
    int i;
    stack<int>s;
    s.push(arr[0]);
    for(i = 1; i < n; i++){
        while(!s.empty() && s.top() < arr[i]) {
            /* Print the greater element. */
            cout<<arr[i]<<" ";
            s.pop();
        }
        /* Push the current element. */
        s.push(arr[i]);
    }
    /* If no greater element then print -1. */
    while(!s.empty()) {
        cout<<"-1"<<" ";
        s.pop();
    }
}
int main() {
    int arr[] = {11, 13, 21, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    findnextgreater(arr, n);
    return 0;
}
