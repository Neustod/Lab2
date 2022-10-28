#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

void Shell(int*, int, int);
void QuickSort(int*, int, int);

int compare(const void* x1, const void* x2) 
{
	return (*(int*)x1 - *(int*)x2);              
}

// Сортировка Шелла
void Shell(int* items, int left, int right) {
	int i = left, j = right, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < right; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

//Функция помогает разделить массив на два подмассива в процедуре QuickSort.
int Partition(int* ArrayPtr, int start, int end) {
	int temp = 0;

	int x = ArrayPtr[end];

	do {
		while (ArrayPtr[start] < x) start++;
		while (x < ArrayPtr[end]) end--;
		if (start <= end) {
			temp = ArrayPtr[start];
			ArrayPtr[start] = ArrayPtr[end];
			ArrayPtr[end] = temp;

			start++;
			end--;
		}
	} while (start <= end);
	return end;
}

//Процедура "Быстрой сортировки".
void QuickSort(int* ArrayPtr, int start, int end) {
	int q;

	if (start < end) {
		q = Partition(ArrayPtr, start, end);
		QuickSort(ArrayPtr, start, q);
		QuickSort(ArrayPtr, q + 1, end);
	}
}

void TimeTestForMulMatrix(int size) {
	unsigned int start;
	vector<vector<int>> a(size), b(size), c(size, vector<int>(size, 0));

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i].push_back(rand() % 100 + 1);
			b[i].push_back(rand() % 100 + 1);
		}
	}

	start = clock();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int r = 0; r < size; r++) c[i][j] += a[i][r] * b[r][j];
		}
	}
	start = clock() - start;

	printf("Время выполнения алгоритма: %.3lfs\n", start / 1000.0);

}

void TimeTestSysQuSort(int size, bool random, bool sortedUp, bool dual) {
	unsigned int start;
	int* a = (int*)malloc(sizeof(int) * size);

	if (random) {
		for (int i = 0; i < size; i++) a[i] = rand() % 100 + 1;
	}
	else if (dual) {
		for (int i = 0; i < size / 2 + size % 2; i++) { a[i] = i; }
		for (int i = size / 2 + size % 2; i < size; i++) { a[i] = size - i - 1; }
	}
	else if (sortedUp)
		for (int i = 0; i < size; i++) a[i] = i;
	else
		for (int i = 0; i < size; i++) a[i] = size - i;

	start = clock();

	qsort(a, size, sizeof(int), compare);

	start = clock() - start;

	printf("Время выполнения алгоритма: %.3lfs\n", start / 1000.0);

	free(a);
};

void TimeTest(void(*sort)(int*, int, int), int size, bool random, bool sortedUp, bool dual) {
	unsigned int start;
	int* a = (int*)malloc(sizeof(int) * size);
	srand(time(NULL));

	if (random) {
		for (int i = 0; i < size; i++) a[i] = rand() % 100 + 1;
	}
	else if (dual) {
		for (int i = 0; i < size / 2 + size % 2; i++) { a[i] = i; }
		for (int i = size / 2 + size % 2; i < size; i++) { a[i] = size - i - 1; }
	}
	else if (sortedUp)
		for (int i = 0; i < size; i++) a[i] = i;
	else
		for (int i = 0; i < size; i++) a[i] = size - i;

	start = clock();

	sort(a, 0, size - 1);

	start = clock() - start;

	printf("Время выполнения алгоритма: %.3lfs\n", start / 1000.0);

	free(a);
}