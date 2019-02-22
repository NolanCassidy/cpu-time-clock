#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void inner(float *u, float *v, int length, float *dest) {
	int i;
	float sum = 0.0f;
	for (i = 0; i < length; ++i) {
		sum += u[i] * v[i];
	}
	*dest = sum;
}

void inner2(float *u, float *v, int length, float *dest) {
	int i;
	float sum = 0.0f;
	for (i = 0; i < length - 3; i+=4) {
		sum += u[i] * v[i];
		sum += u[i+1] * v[i+1];
		sum += u[i+2] * v[i+2];
		sum += u[i+3] * v[i+3];
	}
	*dest = sum;
}

int main(){
	int length = 100000;
	float d = 0;
	float *dest = &d;
	float u[length];
	float v[length];
	for(int i =0; i < length; ++i){
		u[i] = (float)i;
		v[i] = (float)(length-i);
	}
	clock_t start = clock();
	inner(u,v,length,dest);
	clock_t end = clock();
	double inner_time = (double)(end-start)/CLOCKS_PER_SEC;
	printf("Time of inner loop: %f\n",inner_time);
	start = clock();
	inner(u,v,length,dest);
	end = clock();
	double inner2_time = (double)(end-start)/CLOCKS_PER_SEC;
	printf("Time of inner2 loop: %f\n",inner2_time);
}
