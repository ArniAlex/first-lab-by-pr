/*
20.Реализовать функцию преобразования числа типа int, заданного в системе счисления с
основанием 10, в строковое представление числа в системе счисления с основанием из
диапазона [2..36].
*/

#include <stdio.h>

char* translation(int number, int base) { //переводим
	char res[BUFSIZ];
	char *ptr = res + BUFSIZ - 1; // указатель на последний символ 
	int k;

	*ptr = 0; // инициализируем последний символ нулем
	ptr--; 

	while (number != 0) {
		k = number % base;
		* ptr -- = (k > 9) ? k - 10 + 'A' : k + '0';
		number /= base;
	}
	return ptr + 1;
}

int main() {
	int num, base;

	printf("Enter a number: ");
	scanf_s("%d", &num);
	
	printf("Enter a base: ");
	scanf_s("%d", &base);

	printf("The %d in the %d number system is: %s", num, base, translation(num, base));
}