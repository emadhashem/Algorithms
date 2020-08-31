#include <bits/stdc++.h>

using namespace std;
const int mx_n = 1e6 + 9;

void swap_val(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// make the partition work for the sort
int partition_pivot(int arr [], int l , int r) {
    int pvt = r;
    int idx = l;
    for(int i = l; i < r; i++) {
        if(arr[i] < arr[pvt]) {
            swap_val(&arr[i] , &arr[idx]);
            ++idx;
        }
    }
    swap_val(&arr[idx] , &arr[pvt]);
    return idx;
}
// make a random position for the new pivot  and swap it with the last element
int partition_rondom(int arr [], int l, int r) {
    int n = rand();
    int pos = l + n % (r - l + 1);
    swap_val(&arr[pos] , &arr[r]);
    return partition_pivot(arr , l , r);
}
void quick_sort(int arr [], int l, int r) {
    if(l < r) {
        int pivot = partition_rondom(arr , l , r);

        quick_sort(arr , l , pivot - 1);
        quick_sort(arr , pivot + 1 , r);
    }
}

int main() {
    int n;
    int arr[100006];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quick_sort(arr , 0 , n - 1);
    for(int i = 0; i < n; i++) cout << arr[i] << " " ;
    return 0;
}
