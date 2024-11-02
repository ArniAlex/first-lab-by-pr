/*
� ��������� ����� ����� ������������� ������. �������������� ������ �����
���������� � ������. ���� ����������. ���������� ������� ������ �� �����, ���������
������ � ����� � ���� ������� ������������ � ����������� ��������. ��� ����������
����������� ������� �� ������� 4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPENNING_ERROR 10

// ���������� ����� 
void numToFile(const char* ourfile) {
    FILE* fl = fopen(ourfile, "w"); // ��������� ���� ��� ������

    if (fl == NULL) {
        return OPENNING_ERROR; // ������� �� ������� � ������ ������  
    }

    int i, size;

    srand(time(NULL));

    printf("Enter the number of numbers in file: ");
    scanf_s("%d", &size);

    for (i = 0; i < size; i++) { 
        fprintf(fl, "%d ", rand());
    }

    fclose(fl); // ��������� ����
}

// ����� ������������� � ������������ ��������� 
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

    printf("Enter input file name: "); // ��� ��������� ����� 
    scanf_s("%s", sin, sizeof(sin));

    numToFile(sin); // ��������� ���� 

    FILE* fl = fopen(sin, "r"); // ��������� ���� ��� ������
    if (fl == NULL) {
        printf("Openning error\n");
        return OPENNING_ERROR; // ������� ���� ������ 
    }

    printf("Arry elements:\n");

    // ��������� ������ � ����� � ������������� ������ 
    while (fscanf_s(fl, "%d", &num, sizeof(num)) != EOF) {
        m2[y] = num;
        printf("%d ", num);
        y++;
    }
    fclose(fl);

    puts("");

    MiMa(m2, y); // �������� ������� �������

    return 0;
}