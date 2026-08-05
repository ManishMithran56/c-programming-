#include <stdio.h>
int max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}
int max_of_four(int a, int b, int c, int d) {
    int left_max = max(a, b);
    int right_max = max(c, d);
    return max(left_max, right_max);
}

int main() {
    int a, b, c, d;
    if (scanf("%d %d %d %d", &a, &b, &c, &d) == 4) {
        int ans = max_of_four(a, b, c, d);
        printf("%d\n", ans);
    }
    return 0;
}
