//1.Реализовать алгоритм сортировки пузырьком массива чисел.

#include <stdio.h>
#pragma warning (disable:4996)
//организовать перебор элементов целочисленного массива, введённого с клавиатуры, так, чтобы больший элемент стал элементом с большим индексом. сортировать до тех пор, пока все элементы не встанут в порядке возрастания

int main() {

	int m[BUFSIZ];
	int i; //количество элементов массива
	int y, p; //помогатор и временная переменная
	int yes=0;//счётчмк правильности...

	printf("Specify the length of the array: ");
	scanf("%d", &i);

	if (i > BUFSIZ) { //проверка 1
		printf("Oops...enter a number less than ");
		return 10;
	}

	for (y = 0; y < i; y++) { //забиваем массив
		printf("Enter the %d element: ", y+1);
		scanf("%d", &m[y]);
	}
	while (yes!=i-1){
		yes = 0;
		for (y = 0; y < i; y++) { //сортируем
			if (m[y] > m[y + 1]) {
				p = m[y];
				m[y] = m[y + 1];
				m[y + 1] = p;
			}
			else
				++yes;
		}
	}

	printf("The result: ");
	for (y = 0; y < i; y++) {
		printf("%d ", m[y]);
	}
	return 0;
}