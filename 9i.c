//Дан массив значений типа double. Скопировать его в новый массив, удаляя повторяющиеся значения

#include <stdio.h>
#include <math.h>

int main() {
	double c[BUFSIZ], c1[BUFSIZ];
	int len, i, i1;
	int p=0, b;//количество повторений
	double epsilon = 0.000001;

	printf("Enter the size: ");
	scanf_s("%d", &len);

	for (i = 0; i < len; i++) {
		c1[i] = 0.0; 
	}

	for (i = 0; i <= len; i++) {
		printf("Enter the %d float number: ", i+1);
		scanf_s("%lf", &c[i]);
		b = 0;
		for (i1 = 0; i1 < (i-p); i1++) {
			if (fabs(c1[i1]- c[i]) < epsilon) {
				b=1; 
				break;
			}
		}
		if (b == 0) {
			c1[i - p] = c[i];
			printf("\tThe %d element of the second array is: %lf\n", i - p + 1, c1[i - p]);
		}
		else
			p++;

	}
	return 0;
}