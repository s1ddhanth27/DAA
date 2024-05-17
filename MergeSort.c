#include <stdio.h>

void merge(int *a, int lb, int mid, int ub) {
    int b[10];
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    
	if( j > ub){
		while (i <= mid) {
	        b[k] = a[i];
	        i++;
	        k++;
    	}
	}
    
	if( i > mid ){
		while (j <= ub) {
	        b[k] = a[j];
	        j++;
	        k++;
    	}
	}
    

    for (int x = lb; x <= ub; x++) {
        a[x] = b[x];
    }
}

void mergeSort(int *a, int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main() {
    int a[] = {4, 3, 6, 8, 2, 9, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int lb = 0;
    int ub = n - 1;

    mergeSort(&a[0], lb, ub);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

