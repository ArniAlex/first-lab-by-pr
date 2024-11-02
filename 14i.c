/*
В текстовом файле задан целочисленный массив. Разделительный символ между
значениями – пробел. Файл корректный. Необходимо считать данные из файла, заполнить
массив и найти в этом массиве максимальный и минимальные элементы. При реализации
используйте функцию из задания 4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPENNING_ERROR 10

// Заполнение файла 
void numToFile(const char* ourfile) {
    FILE* fl = fopen(ourfile, "w"); // Открываем файл для записи

    if (fl == NULL) {
        return OPENNING_ERROR; // Возврат из функции в случае ошибки  
    }

    int i, size;

    srand(time(NULL));

    printf("Enter the number of numbers in file: ");
    scanf_s("%d", &size);

    for (i = 0; i < size; i++) { 
        fprintf(fl, "%d ", rand());
    }

    fclose(fl); // Закрываем файл
}

// Поиск максимального и минимального элементов 
void MiMa(int* ptr, int size) {
    int min = 100000, max = -100000;
    int iMin = 0, iMax = 0;

    for (int r = 0; r < size; r++) {
        if (ptr[r] > max) {
            max = ptr[r];
            iMax = r;
        }
        if (ptr[r] < min) {
            min = ptr[r];
            iMin = r;
        }
    }
    printf("%s%10s%15s\n", "variable", "index", "meaning");
    printf("min%15d%15d\nmax%15d%15d", iMin, min, iMax, max);
}

int main() {
    char sin[100];
    int num;
    int m2[BUFSIZ];
    int y = 0;

    printf("Enter input file name: "); // Имя выходного файла 
    scanf_s("%s", sin, sizeof(sin));

    numToFile(sin); // Заполнили файл 

    FILE* fl = fopen(sin, "r"); // Открываем файл для чтения
    if (fl == NULL) {
        printf("Openning error\n");
        return OPENNING_ERROR; // Возврат кода ошибки 
    }

    printf("Arry elements:\n");

    // Считываем данные с файла в целочисленный массив 
    while (fscanf_s(fl, "%d", &num, sizeof(num)) != EOF) {
        m2[y] = num;
        printf("%d ", num);
        y++;
    }
    fclose(fl);

    puts("");

    MiMa(m2, y); // Передача размера массива

    return 0;
}