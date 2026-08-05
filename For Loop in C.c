#include <stdio.h>

int main() {
    int a, b;
    if (scanf("%d\n%d", &a, &b) != 2) return 0;
    
    // Array lookup mapping numbers 1 to 9 (0 index left empty for alignment)
    char *words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    // Execute loop from a to b inclusive
    for (int i = a; i <= b; i++) {
        if (i >= 1 && i <= 9) {
            printf("%s\n", words[i]);
        } else if (i > 9) {
            if (i % 2 == 0) {
                printf("even\n");
            } else {
                printf("odd\n");
            }
        }
    }
    
    return 0;
}
