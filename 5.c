//Дан массив целых чисел типа int. Реализовать алгоритм двоичного поиска элемента, значение которого запрашивается у пользователя из стандартного потока ввода.

#include <stdio.h>

int binarySearch(const int y[], int low, int high, int number); // прототип функции

int main() {
	int m[BUFSIZ];
	int min=0, max=0; 
	int i;
	int num, inum;

	printf("Enter the the minimum and maximum elements of the array: ");
	scanf_s("%d%d", &min, &max); //проверить правильность работы

	for (i = 0; i <= max - min + 1; i++) { //заполняем массив
		m[i] = min + i;
	}

	printf("What number do you want to find in the range from %d to %d? Enter: ", min, max);
	scanf_s("%d", &num);
	
	inum = binarySearch(m, 0, max - min, num); //изменить max-min на вычисленную длину массива при другом алгоритме ввода чисел в массив

	printf("\nThe desired number:\nindex    number\n%d%9d", inum, num);

	return 0;
}

int binarySearch(const int y[], int low, int high, int number) {
	int mid;

	while (low <= high) {
		mid = (high + low) / 2;
		if (number == y[mid]) //вывести индекс найденного значения
			return mid;
		else if (number < y[mid])
			high = mid;
		else if (number > y[mid])
			low = mid;
	}
	printf("The desired value was not found "); 
	return -1;
}