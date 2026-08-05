#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *s = malloc(1024 * sizeof(char));
    if (s == NULL) return 1;
    
    // Read the entire line until a newline character is hit
    if (scanf("%[^\n]", s) == 1) {
        // Tokenize the string using spaces as the delimiter
        char *token = strtok(s, " ");
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, " ");
        }
    }
    
    free(s);
    return 0;
}
