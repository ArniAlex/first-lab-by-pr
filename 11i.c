//����������� ������� �������� ����� ������, ����������� ����������� ������� strlen.

#include <stdio.h>

int strlen2(char i[]) { //������� ������� �� ������������ ����
	int u = 0;

	while (i[u] != '\0') {
		u++;
	}

	return u;
}

int main() {
	char input[BUFSIZ];
	
	printf("Enter the string: ");//����������� ������
	scanf_s("%s", input, BUFSIZ);  

	int length = strlen2(input);   //��������� �������

	printf("The length of the string is: %d\n", length);  //������� �������� ������

	return 0;
}
