//1.  опирование: strcat копирует символы из второй строки (источник) в конец первой строки (цель)  до тех пор, пока не встретит символ нулевого завершени€ (\0).
//2. ƒобавление нулевого символа : ¬ конце полученной строки добавл€етс€ символ нулевого завершени€(\0), чтобы обозначить ее конец.

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


void myStrcat(char* dest, const char* src);
//создать строку размера 100, динамически увеличивать размер при переполнениии в 2 раза
//запрашивать строку и забрасывать еЄ в конец предыдущей по указателю в функции


int main() {
	char *str1=(char *)calloc(100, sizeof(char)); 
	char *string = NULL;
    char* for_realloc;
	int arrSize=1;
        
	if (str1==NULL) { 
		printf("Error");
        return 1;
	}
	printf("Now it is necessary to enter lines.\nIf you want to stop enter: STOP\n");

	while (1) { //считываем строки до слова STOP
		// ¬ыдел€ем пам€ть дл€ строки, считываемой с клавиатуры
		string = (char *)malloc(100); 
		if (string == NULL) { 
			printf("Error\n");
			free(str1);
			return 10;
		}
		printf("Enter the string: \n");

		//проверить, что в массиве хватает места 
        if (fgets(string, 100, stdin) == NULL) { 
            printf("Error reading input.\n");
            free(str1);
            free(string);
            continue;
        }

		string[strcspn(string, "\n")] = '\0';

        if (!strcmp(string, "STOP"))//проверка на слово стоп 
        {
            free(string);
            break;
        }

		while(100*arrSize-strlen(str1)+1<strlen(string)){ //если недостаточно пам€ти дл€ строки с консоли- выдел€ем больше пам€ти под массив
			arrSize *= 2;
			for_realloc = (char *)realloc(str1, arrSize * 100);

			if (for_realloc == NULL) {
				printf("Error...");
				free(string);
				free(str1);
				return 100;
			}

            str1 = for_realloc;
		}

		myStrcat(str1, string);
		free(string);  
	}

	printf("The result: %s", str1);
	free(str1);

	return 0;
}

void myStrcat(char* dest, const char* source) {
	//base[strlen(base) - 1] = input;
	// Ќаходим конец строки base
	char* p = dest;
	while (*p != '\0') { // while (*p++);
		p++;
	}

	//  опируем input в конец base
	while (*source != '\0') {
		*p++ = *source++;
	}

	// ƒобавл€ем нулевой символ в конец base
	*p = '\0';
}
