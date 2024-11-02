//��� ������ ����� ����� ���� int. ����������� �������� ��������� ������ ��������, �������� �������� ������������� � ������������ �� ������������ ������ �����.

#include <stdio.h>

int binarySearch(const int y[], int low, int high, int number); // �������� �������

int main() {
	int m[BUFSIZ];
	int min=0, max=0; 
	int i;
	int num, inum;

	printf("Enter the the minimum and maximum elements of the array: ");
	scanf_s("%d%d", &min, &max); //��������� ������������ ������

	for (i = 0; i <= max - min + 1; i++) { //��������� ������
		m[i] = min + i;
	}

	printf("What number do you want to find in the range from %d to %d? Enter: ", min, max);
	scanf_s("%d", &num);
	
	inum = binarySearch(m, 0, max - min, num); //�������� max-min �� ����������� ����� ������� ��� ������ ��������� ����� ����� � ������

	printf("\nThe desired number:\nindex    number\n%d%9d", inum, num);

	return 0;
}

int binarySearch(const int y[], int low, int high, int number) {
	int mid;

	while (low <= high) {
		mid = (high + low) / 2;
		if (number == y[mid]) //������� ������ ���������� ��������
			return mid;
		else if (number < y[mid])
			high = mid;
		else if (number > y[mid])
			low = mid;
	}
	printf("The desired value was not found "); 
	return -1;
}