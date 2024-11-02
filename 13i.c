//»меетс€ строка. »спользу€ указатель типа char *, преобразовать каждый элемент, сто€щий на нечЄтной позиции, в верхний регистр.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void Str(char* str) {
    for (int i = 1; str[i] != NULL; i=i+2) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char yj[BUFSIZ];

    printf("Enter the string: ");
    gets(yj);

    Str(yj);
    printf("The result: %s", yj);

    return 0;
}