//«адан числовой массив. ѕереписать в новый массив числа, сто€щие на нечЄтных позици€х.

#include <stdio.h>

int main() {
	int arr1[BUFSIZ];
	int arr2[BUFSIZ];
	int sizar; //размер массива
	int i; //перебор

	printf("Enter the size (less then %d): ", BUFSIZ);
	scanf_s("%d", &sizar);

	if (sizar > BUFSIZ) {
		printf("Enter a less then");
		return 10;
	}

	for (i = 0; i < sizar; i++) { //заполн€ем массив
		printf("Enter the %d number: ", i);
		scanf_s("%d", &arr1[i]);
	}

	for (i = 1; i < sizar; i += 2) {
		arr2[i / 2] = arr1[i];
		printf("%d ", arr2[i / 2]);
	}

	return 0;
}