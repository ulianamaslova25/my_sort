#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include "sorts.h"



int main() {
	int n = 0;
	int flag = choise();
	srand(time(NULL));
	for (int i = 1; i <= 6; i++) {
		n = 500 * (i % 2 + 2 * (i % 2 == 0));
		if (i == 3 || i == 4) {
			n *= 10;
		}
		if (i == 5 || i == 6) {
			n *= 100;
		}
		/*if (i == 7) {
			n *= 1000;
		}*/
		double* a = (double*)malloc(n * sizeof(double));
		for (int i = 0; i < n; i++) {
			a[i] = rand();
			//printf_s("%lf ", a[i]);
		}
		/*for (int i = 0; i < n; i++) {
			a[i] = n - i;
			//printf_s("%lf ", a[i]);
		}*/
		work(a, n, flag);
		free(a);
	}
	/*n = 10;
	double* mas = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		a[i] = n - i;
		printf_s("%lf ", a[i]);
	}
	work(mas, n, flag);
	free(mas);*/
	//free(a500000);
	/*double* a = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		a[i] = n - i;
		printf_s("%lf ", a[i]);
	}
	printf_s("\n");
	choise(a, n);
	printf_s("\n");*/
}