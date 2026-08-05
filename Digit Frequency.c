#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *s = malloc(1001 * sizeof(char));
    if (s == NULL) return 1;
    
    if (scanf("%s", s) != 1) {
        free(s);
        return 0;
    }
    
    // Frequency array initialized to 0 for digits 0-9
    int freq[10] = {0};
    
    for (int i = 0; s[i] != '\0'; i++) {
        // Check if character is between '0' and '9'
        if (s[i] >= '0' && s[i] <= '9') {
            freq[s[i] - '0']++;
        }
    }
    
    // Print the frequencies separated by space
    for (int i = 0; i < 10; i++) {
        printf("%d ", freq[i]);
    }
    printf("\n");
    
    free(s);
    return 0;
}
