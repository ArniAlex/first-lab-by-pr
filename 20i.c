/*
20.����������� ������� �������������� ����� ���� int, ��������� � ������� ��������� �
���������� 10, � ��������� ������������� ����� � ������� ��������� � ���������� ��
��������� [2..36].
*/

#include <stdio.h>

char* translation(int number, int base) { //���������
	char res[BUFSIZ];
	char *ptr = res + BUFSIZ - 1; // ��������� �� ��������� ������ 
	int k;

	*ptr = 0; // �������������� ��������� ������ �����
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