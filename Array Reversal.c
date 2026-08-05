#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Print the array in reverse order
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    
    free(arr);
    return 0;
}
