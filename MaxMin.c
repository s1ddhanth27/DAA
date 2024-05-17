#include <stdio.h>
struct temp {
    int min;
    int max;
};

struct temp maxMin(int a[], int l, int r) {
    struct temp mm, mmLeft, mmRight;

    if (l == r) {
        mm.max = a[l];
        mm.min = a[l];
    }
    else if (l == r - 1) {
        if (a[l] < a[r]) {
            mm.min = a[l];
            mm.max = a[r];
        } else {
            mm.min = a[r];
            mm.max = a[l];
        }
    }
    else {
        int mid = (l + r) / 2;
        mmLeft = maxMin(a, l, mid);
        mmRight = maxMin(a, mid + 1, r);
        mm.min = (mmLeft.min < mmRight.min) ? mmLeft.min : mmRight.min;
        mm.max = (mmLeft.max > mmRight.max) ? mmLeft.max : mmRight.max;
    }
    return mm;
}

int main() {
    int arr[] = {4, 3, 7, 9, 11, 45, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct temp mm = maxMin(arr, 0, n - 1);
    printf("Max: %d\tMin: %d\n", mm.max, mm.min);
    return 0;
}

