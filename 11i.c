//Реализовать функцию подсчета длины строки, аналогичную стандартной функции strlen.

#include <stdio.h>

int strlen2(char i[]) { //считаем символы до завершающего нуля
	int u = 0;

	while (i[u] != '\0') {
		u++;
	}

	return u;
}

int main() {
	char input[BUFSIZ];
	
	printf("Enter the string: ");//запрашиваем строку
	scanf_s("%s", input, BUFSIZ);  

	int length = strlen2(input);   //реализуем функцию

	printf("The length of the string is: %d\n", length);  //выводим конечную строку

	return 0;
}
