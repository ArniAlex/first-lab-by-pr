// Дана квадратная матрица. Реализовать алгоритм транспонирования матрицы.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tr(int m[][100], int m2[][100], int i, int j) { //транспонирует матрицу

	for (int j1 = 0; j1 < j; j1++) {
		for (int i1 = 0; i1 < i;i1++) {
			m2[j1][i1] = m[i1][j1];
		}
	}
} 

void zap(int b[][100], int i, int j) { //заполняет начальную матрицу
	srand(time(NULL));

	printf("The initial matrix:\n");
	for (int i1 = 0; i1 < i; i1++) {
		for (int j1 = 0; j1 < j; j1++) {
			b[i1][j1] = rand();
			printf("%d ", b[i1][j1]);
		}
		puts(""); 
	}
}

int main() {
	int m1[100][100];
	int m2[100][100]; 
	int i, j;

	printf("Enter the size of the matrix:\n");
	printf("rows: ");
	scanf_s("%d", &i);
	printf("cols: ");
	scanf_s("%d", &j);
	puts("");

	zap(m1, i, j);

	printf("\nTransposed Matrix:\n");
	tr(m1, m2, i, j); 

	for (int i1 = 0; i1 < j; i1++) { // Выводим транспонированную матрицу
		for (int j1 = 0; j1 < i; j1++) {
			printf("%d ", m2[i1][j1]);
		}
		puts("");
	}
	return 0;
}