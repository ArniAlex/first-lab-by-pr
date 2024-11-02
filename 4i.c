/*Заполнить массив фиксированного размера псевдослучайными целыми числами в
диапазоне [-10000..10000]. Реализовать алгоритм поиска максимального и минимального
элементов массива, а также индексов этих элементов, за один проход по массиву*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int c[BUFSIZ] = { 0 };
	int csize = 0; //длина массива
	int r; //счётчик
	int min = 10001, max = -10001;
	int iMin = 0, iMax = 0;

	printf("Enter the size of array: ");
	scanf_s("%d", &csize);

	if (csize > BUFSIZ) {
		printf("Enter the other number");
		return 1;
	}

	for (r = 0; r < csize; r++) {
		c[r] = rand() % 20001 - 10000;//массив из псевдослучайных целых от -10000 до 10000
	}

	for (r = 0; r < csize; r++) {
		if (c[r] > max) {
			max = c[r];
			iMax = r;
		}
		if (c[r] < min) {
			min = c[r];
			iMin = r;
		}
	}

	printf("%s%15s%22s\n", "variable", "index", "meaning");
	printf("min%10d%15d\nmax%10d%15d", iMin, min, iMax, max);
	return 0;
}