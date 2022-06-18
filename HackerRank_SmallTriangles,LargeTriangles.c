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
double get_area (triangle tr){
    double p;
    p = ((double)tr.a + (double)tr.b + (double)tr.c)/2;
    
    double s;
    double under_s = (p * (p-(double)tr.a) * (p-(double)tr.b) * (p-(double)tr.c) );
    s = sqrt( under_s );
    return s;
}
void sort_by_area(triangle* a, int n) {
	/* Sort an array a of the length n */
    for(int i = 0; i < n-1; i++){
        for(int j = i+1 ; j < n ; j++){
            triangle cont;
            if(get_area(a[i]) > get_area(a[j]) ){
                cont = a[i];
                a[i] = a[j];
                a[j] = cont;
            }   
        }
    }
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