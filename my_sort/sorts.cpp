#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

void swap(double* a, double* b) {
	double i = *a;
	*a = *b;
	*b = i;
}

double max(double* a, int n) {
	double maximum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > maximum) maximum = a[i];
	}
	return maximum;
}

int partition(double* a, int low, int high) {
	double med = a[high];
	int cnt = low - 1;
	for (int i = low; i < high; i++) {
		if (a[i] < med) {
			cnt++;
			swap(&a[cnt], &a[i]);
		}
	}
	swap(&a[cnt + 1], &a[high]);
	return (cnt + 1);
}

void merge(double* a, int low, int med, int high) {
	int k = low;
	int f = med - low + 1;
	int p = high - med;
	const int n1 = f;
	const int n2 = p;
	double* left = (double*)malloc(n1 * sizeof(double));
	double* right = (double*)malloc(n2 * sizeof(double));
	for (int i = 0; i < n1; i++) {
		left[i] = a[low + i];
	}
	for (int j = 0; j < n2; j++) {
		right[j] = a[med + 1 + j];
	}
	int i = 0;
	int j = 0;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			a[k] = left[i];
			i++;
		}
		else {
			a[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		a[k] = left[i];
		i++;
		k++;
	}
	while (j < n2) {
		a[k] = right[j];
		j++;
		k++;
	}
}

void select_sort(double* a, int n) {
	setlocale(LC_ALL, "Rus");
	printf_s("---Сортировка select_sort---\n");
	int i = 0;
	int minInd = -1;
	int time = 0;
	int begin = 0;
	int end = 0;
	begin = clock();
	for (int i = 0; i < n; i++) {
		minInd = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[minInd]) {
				minInd = j;
			}
		}
		swap(&a[i], &a[minInd]);
	}
	end = clock();
	for (int i = 0; i < n; i++) {
		//printf_s("%lf ", a[i]);
	}
	time = end - begin;
	printf_s("Количество элементов в массиве: %d\n", n);
	printf_s("Время работы программы: %lf секунд\n", (double)time / CLOCKS_PER_SEC);
	printf_s("\n");
}

void insert_sort(double* a, int n) {
	setlocale(LC_ALL, "Rus");
	printf_s("---Сортировка insert_sort---\n");
	double key;
	int time = 0;
	int begin = 0;
	int end = 0;
	begin = clock();
	for (int i = 0; i < n - 1; i++) {
		key = a[i + 1];
		for (int j = i; j >= 0; j--) {
			if (key < a[j]) {
				swap(&a[j], &a[j + 1]);
			}
			else break;
		}
	}
	end = clock();
	time = end - begin;
	for (int i = 0; i < n; i++) {
		//printf_s("%lf ", a[i]);
	}
	printf_s("Количество элементов в массиве: %d\n", n);
	printf_s("Время работы программы: %lf секунд\n", (double)time / CLOCKS_PER_SEC);
	printf_s("\n");
}

void bubble_sort(double* a, int n) {
	setlocale(LC_ALL, "Rus");
	printf_s("---Сортировка bubble_sort---\n");
	int time = 0;
	int begin = 0;
	int end = 0;
	int cnt = 0;
	begin = clock();
	for (int i = 0; i < n - 1; i++) {
		cnt = 0;
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				cnt++;
				swap(&a[j], &a[j + 1]);
			}
		}
		if (cnt == 0) break;
	}
	end = clock();
	for (int i = 0; i < n; i++) {
		//printf_s("%lf ", a[i]);
	}
	time = end - begin;
	printf_s("Количество элементов в массиве: %d\n", n);
	printf_s("Время работы программы: %lf секунд\n", (double)time / CLOCKS_PER_SEC);
	printf_s("\n");
}

void counting_sort(double* a, int n) {
	setlocale(LC_ALL, "Rus");
	printf_s("---Сортировка counting_sort---\n");
	int time = 0;
	int begin = 0;
	int end = 0;
	int cnt = 0;
	int maxi = (int)max(a, n);
	int* count = (int*)malloc((maxi + 1) * sizeof(int));
	int* mass = (int*)malloc(n * sizeof(int));
	begin = clock();
	for (int i = 0; i <= maxi; ++i) {
		count[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		count[(int)a[i]]++;
	}
	for (int i = 1; i <= maxi; i++) {
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		mass[count[(int)a[i]] - 1] = a[i];
		count[(int)a[i]]--;
	}
	for (int i = 0; i < n; i++) {
		a[i] = mass[i];
	}
	end = clock();
	for (int i = 0; i < n; i++) {
		//printf_s("%lf ", a[i]);
	}
	time = end - begin;
	printf_s("Количество элементов в массиве: %d\n", n);
	printf_s("Время работы программы: %lf секунд\n", (double)time / CLOCKS_PER_SEC);
	printf_s("\n");
	free(count);
	free(mass);
}

void quick_sort(double* a, int low, int high) {
	if (low < high) {
		int p = partition(a, low, high);
		quick_sort(a, low, p - 1);
		quick_sort(a, p + 1, high);
	}
}

void merge_sort(double* a, int low, int high) {
	if (low < high) {
		int med = low + (high - low) / 2;
		merge_sort(a, low, med);
		merge_sort(a, med + 1, high);
		merge(a, low, med, high);
	}
}

int choise() {
	setlocale(LC_ALL, "Rus");
	int flag = 0;
	printf_s("Пожалуйста, выбирите сортировку\n");
	printf_s("1 - select_sort\n");
	printf_s("2 - insert_sort\n");
	printf_s("3 - bubble_sort\n");
	printf_s("4 - quick_sort\n");
	printf_s("5 - counting_sort\n");
	printf_s("6 - merge_sort\n");
	scanf_s("%d", &flag);
	return flag;
}

void work(double* a, int n, int flag) {
	switch (flag) {
	case 1: select_sort(a, n); break;
	case 2: insert_sort(a, n); break;
	case 3: bubble_sort(a, n); break;
	case 4: {
		setlocale(LC_ALL, "Rus");
		printf_s("---Сортировка quick_sort---\n");
		int time = 0;
		int begin = 0;
		int end = 0;
		begin = clock();
		quick_sort(a, 0, n - 1);
		end = clock();
		time = end - begin;
		printf_s("Количество элементов в массиве: %d\n", n);
		printf_s("Время работы программы: %lf секунд\n", (double)time / CLOCKS_PER_SEC);
		printf_s("\n");
		for (int i = 0; i < n; i++) {
			//printf_s("%d\n", (int)a[i]);
		}
		break;
	}
	case 5: {
		for (int i = 0; i < n; i++) {
			a[i] = (int)a[i];
		}
		counting_sort(a, n);
		break;
	}
	case 6: {
		setlocale(LC_ALL, "Rus");
		printf_s("---Сортировка merge_sort---\n");
		int time = 0;
		int begin = 0;
		int end = 0;
		begin = clock();
		merge_sort(a, 0, n - 1);
		end = clock();
		time = end - begin;
		printf_s("Количество элементов в массиве: %d\n", n);
		printf_s("Время работы программы: %lf секунд\n", (double)time / CLOCKS_PER_SEC);
		printf_s("\n");
		for (int i = 0; i < n; i++) {
			//printf_s("%lf ", a[i]);
		}
		break;
	}
	}
}