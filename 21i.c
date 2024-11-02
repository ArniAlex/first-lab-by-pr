/*
21.Реализовать функцию преобразования строкового представления числа в системе
счисления с основанием из диапазона [2..36] в число типа int, заданного в системе
счисления с основанием 10.
*/
#include <stdio.h>
#include <ctype.h>

int ten(const char* str, int base) {
    int i;
	int res = 0;

	for (i = 0; str[i] != NULL; i++) {
		if (isdigit(str[i]))
			res = res * base + (str[i] - '0');
		else if (isupper(str[i]))
			res = res * base + (str[i] - 'A' + 10);
		else if (islower(str[i]))
			res = res * base + (str[i] - 'a' + 10);
	}
	return res;
}

//ищем минимально возможное основание для введённого числа
int min(char* str) {
	int minBase = 2;
	int i;
	for (i = 0; str[i] != '\0'; i++) { 
		if (str[i] > minBase) {
			minBase = str[i]; 
		}
	}

	if (47 < minBase && minBase < 57) 
		minBase -= '0'; 
	else if (64 < minBase && minBase < 91)   
		minBase = minBase - 'A' + 10; 
	else if (96 < minBase && minBase  < 122) 
		minBase = minBase - 'a' + 10; 

	return minBase+1;
}

int main() {
	char inputStr[BUFSIZ];
	int base;
	

	printf("Enter the string\n");
	fgets(inputStr, BUFSIZ, stdin);//считываем строчку с клавиатуры

	printf("Enter the base(from %d to 36): ", min(inputStr));  
	scanf_s("%d", &base);

	printf("The number in the decimal system is: %d", ten(inputStr, base)); 

	return 0;
}