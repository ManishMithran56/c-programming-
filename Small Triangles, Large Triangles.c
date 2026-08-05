#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
double get_squared_area(triangle t) {
    double a = t.a;
    double b = t.b;
    double c = t.c;
    double p = (a + b + c) / 2.0;
    return p * (p - a) * (p - b) * (p - c);
}

int compare_triangles(const void* a, const void* b) {
    triangle* t1 = (triangle*)a;
    triangle* t2 = (triangle*)b;
    
    double area1 = get_squared_area(*t1);
    double area2 = get_squared_area(*t2);
    
    if (area1 < area2) return -1;
    if (area1 > area2) return 1;
    return 0;
}

void sort_by_area(triangle* tr, int n) {
    qsort(tr, n, sizeof(triangle), compare_triangles);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
