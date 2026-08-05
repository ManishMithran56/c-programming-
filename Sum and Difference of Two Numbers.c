#include <stdio.h>

int main() {
    int int1, int2;
    float float1, float2;
    
    if (scanf("%d %d", &int1, &int2) != 2) return 0;
    
    if (scanf("%f %f", &float1, &float2) != 2) return 0;
    
    printf("%d %d\n", int1 + int2, int1 - int2);
    
    printf("%.1f %.1f\n", float1 + float2, float1 - float2);
    
    return 0;
}
