/*
Заданы две матрицы произвольного размера. Реализовать алгоритм умножения матриц. В
случае, если умножение невозможно, необходимо сообщить пользователю об ошибке.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows1, cols1, rows2, cols2;
    int i, j, k;
    int m1[BUFSIZ], m2[BUFSIZ]; //входные массивы
    int mRes[BUFSIZ] = { 0 }; //выходной массив

    printf("Enter the number of rows and columns of the first matrix: "); 
    scanf_s("%d%d", &rows1, &cols1);

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf_s("%d%d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Multiplication cannot be performed!\n");
        return 1;
    }

    srand(time(NULL));

    for (i = 0; i < rows1 * cols1; i++) { 
        m1[i] = rand() % 1001;
    }

    printf("The first matrix is:\n"); //выводим первую матрицу
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) { 
            printf("%d ", m1[i * cols1 + j]); 
        }
        printf("\n");
    }

    for (i = 0; i < rows2 * cols2; i++) {
        m2[i] = rand() % 1001;
    }

    printf("The second matrix is:\n"); //выводим вторую матрицу
    for (i = 0; i < rows2; i++) { 
        for (j = 0; j < cols2; j++) { 
            printf("%d ", m2[i * cols2 + j]);  
        }
        printf("\n");
    }

    //умножение матриц
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            for (k = 0; k < cols1; k++) {
                mRes[i * cols2 + j] += m1[i * cols1 + k] * m2[k * cols2 + j];
            }
        }
    }

    printf("The resulting matrix is:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            printf("%d ", mRes[i * cols2 + j]);
        }
        printf("\n");
    }

    return 0;
}