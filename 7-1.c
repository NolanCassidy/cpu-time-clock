#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 4
typedef int array_t[N][N];

int dim() {
	return N;
}

void f(array_t a, int x, int y) {
	int i,j;		//creates inegers before the loop
	int length = dim();	//stops dim fuction from being called each loop
	int mult = x*y;		//pull multiplication out of loops
	for (i = 0; i < length; ++i) {
		int mult2 = i*mult;	//pull multiplication out of loop
		for (j = 0; j < length; ++j) {
			a[i][j] = mult2 + j;
		}
	}
}

int main(){
	array_t a = {{5,4,3,2},{9,8,7,6},{1,7,5,10},{6,2,5,7}};
	clock_t start = clock();
	f(a,2,4);
	clock_t end = clock();
	double inner_time = (double)(end-start)/CLOCKS_PER_SEC;
	printf("Time of fuction f: %f\n",inner_time);
}
