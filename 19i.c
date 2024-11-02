//���� ���������� �������. ����������� �������� ���������� �������� �������.

#include <stdio.h> 
#include <stdlib.h>  
#include <time.h> 
#include <math.h> // ��� ������� fabs()

#define OKEY 0 

void filling(double matrix[][100], int size);
double determinant(double matrix[][100], int size);
void tr(double m[][100], int size);
void algadd(double matrix[][100], double matrix2[][100], int size);

int main() {
	double matrix[100][100];
	double matrixRes[100][100] = { 0 };
	int size;
	double det = 0;

	printf("Enter the size of the matrix: ");// ����������� ������ 
	scanf_s("%d", &size);

	printf("The matrix:\n");
	filling(matrix, size);

	if (size == 1) {
		printf("Result matrix is %.3lf", 1 / matrix[0][0]);
		return OKEY;
	}

	det = determinant(matrix, size); //��������� ������������ 

	//���������, ���������� �� �������� ������� 
	if (fabs(det) < 0.0001) {
		printf("The determinant is 0, there is no inverse matrix.");
		return OKEY;
	}

	algadd(matrix, matrixRes, size); // ������� �������  
	tr(matrixRes, size); // ������������� ������� ������� 

	// ����� ������ ������� �� ������������
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrixRes[i][j] /= det;  
			printf("%.4lf  ", matrixRes[i][j]);
		}
		puts("");
	}

	return OKEY;
}

//��������� ������ 
void filling(double matrix[][100], int size) {
	srand(time(NULL));//��������� ��������� 

	//���� ��� ����� ��������� ��������� (���������� �������) 
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = rand() % 501;
			printf("%.0lf  ", matrix[i][j]); //������� ��������� ������� �� ����� 
		}
		puts("");
	}
}

//��������� ������������ 
double determinant(double matrix[][100], int size) {
	double result = 0;

	if (size == 1) {
		return matrix[0][0];
	}
	else if (size == 2) {
		return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
	}
	else {
		// ��� �� ������ ������ 
		for (int j = 0; j < size; j++) {
			// ���������� ��� ������ ������ � j-��� ������� 
			double submatrix[100][100];
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

			// ��������� ������������ ���������� 
			double subdeterminant = determinant(submatrix, subsize);

			result += matrix[0][j] * subdeterminant * (j % 2 == 0 ? 1 : -1);
		}
	}
	return result;
}

//������������� �������  
void tr(double m[][100], int size) {
	double m2[100][100] = { 0 };
	for (int j1 = 0; j1 < size; j1++) {
		for (int i1 = 0; i1 < size; i1++) {
			m2[j1][i1] = m[i1][j1];
		}
	}
	for (int j1 = 0; j1 < size; j1++) {
		for (int i1 = 0; i1 < size; i1++) {
			m[j1][i1] = m2[j1][i1];
		}
	}
}

//������� �������  
void algadd(double m[][100], double m2[][100], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			double submatrix[100][100]; //������ ���������� 
			int subsize = size - 1;
			int subK = 0, subW = 0;
			for (int k = 0; k < size; ++k) {
				if (k != i) {
					for (int w = 0; w < size; ++w) {
						if (w != j) {
							submatrix[subK][subW] = m[k][w];
							subW++;
							if (subW == subsize) { // �������� �� ����� �� �������
								subW = 0;
								subK++;
							}
						}
					}
				}
			}
			m2[i][j] = determinant(submatrix, subsize) * ((i + j) % 2 ? -1 : 1); //��������� ������� ������� 
		}
	}
}