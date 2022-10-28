#include "Tests.h"

int main() {
	system("chcp 1251 > nul");

	int i = 0, j = 0, size;
	unsigned int start; // объявляем переменные для определения времени выполнения

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел

	cout << "[Matrix mul]\n";
	TimeTestForMulMatrix(100);
	TimeTestForMulMatrix(200);
	TimeTestForMulMatrix(400);
	TimeTestForMulMatrix(1000);
	/*
	TimeTestForMulMatrix(2000);
	TimeTestForMulMatrix(4000);
	TimeTestForMulMatrix(10000);
	*/

	cout << "\n[Random QuickSort]\n";
	for (int i = 500000; i <= 10000000; i += 500000) { cout << i << " >> "; TimeTest(QuickSort, i, 1, 0, 0); };
	cout << "\n[SortedUp QuickSort]\n";
	for (int i = 500; i <= 4000; i += 500) { cout << i << " >> "; TimeTest(QuickSort, i, 0, 1, 0); };
	cout << "\n[SortedDown QuickSort]\n";
	for (int i = 500; i <= 4000; i += 500) { cout << i << " >> "; TimeTest(QuickSort, i, 0, 0, 0); };
	cout << "\n[Pyramid QuickSort]\n";
	for (int i = 500000; i <= 10000000; i += 500000) { cout << i << " >> "; TimeTest(QuickSort, i, 0, 0, 1); };

	cout << "\n[Random Shell]\n";
	for (int i = 20000; i <= 200000; i += 20000) { cout << i << " >> "; TimeTest(Shell, i, 1, 0, 0); };
	cout << "\n[SortedUp Shell]\n";
	for (int i = 1000000; i <= 10000000; i += 1000000) { cout << i << " >> "; TimeTest(Shell, i, 0, 1, 0); };
	cout << "\n[SortedDown Shell]\n";
	for (int i = 20000; i <= 200000; i += 20000) { cout << i << " >> "; TimeTest(Shell, i, 0, 0, 0); };
	cout << "\n[Pyramid Shell]\n";
	for (int i = 20000; i <= 200000; i += 20000) { cout << i << " >> "; TimeTest(Shell, i, 0, 0, 1); };

	cout << "\n[Random SysQuickSort]\n";
	for (int i = 500000; i <= 10000000; i += 500000) { cout << i << " >> "; TimeTestSysQuSort(i, 1, 0, 0); };
	cout << "\n[SortedUp SysQuickSort]\n";
	for (int i = 500; i <= 4000; i += 500) { cout << i << " >> "; TimeTestSysQuSort(i, 0, 1, 0); };
	cout << "\n[SortedDown SysQuickSort]\n";
	for (int i = 500; i <= 4000; i += 500) { cout << i << " >> "; TimeTestSysQuSort(i, 0, 0, 0); };
	cout << "\n[Pyramid SysQuickSort]\n";
	for (int i = 50000; i <= 1000000; i += 50000) { cout << i << " >> "; TimeTestSysQuSort(i, 0, 0, 1); };

	return 0;
}

