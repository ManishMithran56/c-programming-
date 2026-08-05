#include <stdio.h>
#include <stdlib.h>

void update(int *a, int *b) {
    int temp_a = *a;
    int temp_b = *b;
    
    *a = temp_a + temp_b;
    
    *b = abs(temp_a - temp_b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    if (scanf("%d %d", &a, &b) == 2) {
        update(pa, pb);
        printf("%d\n%d\n", a, b);
    }
    
    return 0;
}
