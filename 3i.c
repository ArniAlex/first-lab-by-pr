// –еализовать функцию, мен€ющую местами значени€ двух чисел типа int. ¬ходными параметрами функции €вл€ютс€ указатели типа int* .

#include <stdio.h> 

void change(int* ptr1, int* ptr2) { //мен€ем местами числа по их адресу
    int f = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = f;
    printf("Now the number %d is located at the address: %p\n and the number %d is located at: %p\n", *ptr2, ptr2, *ptr1, ptr1);
}

int main() {
    int i1 = 0, i2 = 0;

    printf("Enter the first number (located at %p): ", &i1);
    scanf_s("%d", &i1);//запрашиваем значение первого числа

    printf("Enter the second number (located at %p): ", &i2);
    scanf_s("%d", &i2); //запрашиваем значение второго числа

    // ѕередаем адреса переменных i1 и i2
    change(&i1, &i2);

    return 0;
}