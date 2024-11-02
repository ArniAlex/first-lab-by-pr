//Реализовать алгоритм “переворота” (reverse) символьной строки.

#include <stdio.h>
#include <string.h> 

int main() {
	char st[BUFSIZ];
	char res[BUFSIZ];
	int k, l;

	printf("Enter the string: ");
	fgets(st, BUFSIZ, stdin);  //чтобы был завершающий 0

	l = strlen(st);

	for (k = 0; k < l / 2; k++) { //переворачиваем
		res[k] = st[l - k -1];  
		res[l - k-1 ] = st[k];
	}

	if (l % 2 != 0) //центральный символ при нечётной длине
		res[l / 2] = st[l / 2];

	res[l] = '\0';

	printf("\nThe result is: %s", res);
	return 0;
}