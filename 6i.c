//Дана квадратная матрица произвольного размера. Необходимо найти определитель матрицы.

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int determinant(int matrix[][100], int size);

int main() {
	int matrix[100][100];
	int size;
	int det = 0;

	printf("Enter the size of the matrix: ");// запрашиваем размер
	scanf_s("%d", &size);

	srand(time(NULL));//засеиваем генератор

	printf("The matrix:\n");

	//цикл для ввода рандомных элементов
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = rand() % 1000;
			printf("%d  ", matrix[i][j]);
		}
		puts("");
	}

	det = determinant(matrix, size);
	printf("The determinant is: %d\n", det);

	return 0;
}

// Используя рекурсию, вычисляем определитель
int determinant(int matrix[][100], int size) {
	int result = 0;

	if (size == 1) {
		return matrix[0][0];
	}
	else if (size == 2) {
		return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
	}
	else {
		for (int j = 0; j < size; j++) {
			// Подматрица без первой строки и j-ого столбеца
			int submatrix[100][100];
			int subsize = size - 1;
			int subrow = 0;
			for (int i = 1; i < size; i++) {
				int subcol = 0;
				for (int k = 0; k < size; k++) {
					if (k != j) {
						submatrix[subrow][subcol] = matrix[i][k];
						subcol++;
					}
				}
				subrow++;
			}

			// вычисляем определитель подматрицы
			int subdeterminant = determinant(submatrix, subsize);

			result += matrix[0][j] * subdeterminant * (j % 2 == 0 ? 1 : -1);
		}
	}
	return result;
}