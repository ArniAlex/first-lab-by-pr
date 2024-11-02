// Задан числовой массив. Переписать в новый массив чётные числа

#include <stdio.h>

int main() {
	int m1[BUFSIZ];
	int m2[BUFSIZ];
	int i, j = 0; //счётчик
	int lenM;

	printf("Enter the size (less then %d): ", BUFSIZ);
	scanf_s("%d", &lenM);

	for (i = 0; i < lenM; i++) { 
		printf("Enter the %d number:", i);
		scanf_s("%d", &m1[i]);
	}

	for (i = 0; i < lenM; i++) {
		if (m1[i] % 2 == 0) {
			m2[j] = m1[i];
			printf("%d ", m2[j]);
			j++;
		}
	}
	return 0;
}