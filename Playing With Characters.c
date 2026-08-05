#include <stdio.h>

int main() {
    char ch;
    char s[100];
    char sen[100];

    if (scanf("%c", &ch) != 1) return 0;
    
    if (scanf("%s", s) != 1) return 0;
    
    if (scanf("\n") != 0) {} 
    
    if (scanf("%[^\n]%*c", sen) != 1) return 0;

    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);

    return 0;
}
