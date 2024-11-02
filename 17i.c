//1. �����������: strcat �������� ������� �� ������ ������ (��������) � ����� ������ ������ (����)  �� ��� ���, ���� �� �������� ������ �������� ���������� (\0).
//2. ���������� �������� ������� : � ����� ���������� ������ ����������� ������ �������� ����������(\0), ����� ���������� �� �����.

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


void myStrcat(char* dest, const char* src);
//������� ������ ������� 100, ����������� ����������� ������ ��� ������������� � 2 ����
//����������� ������ � ����������� � � ����� ���������� �� ��������� � �������


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

	while (1) { //��������� ������ �� ����� STOP
		// �������� ������ ��� ������, ����������� � ����������
		string = (char *)malloc(100); 
		if (string == NULL) { 
			printf("Error\n");
			free(str1);
			return 10;
		}
		printf("Enter the string: \n");

		//���������, ��� � ������� ������� ����� 
        if (fgets(string, 100, stdin) == NULL) { 
            printf("Error reading input.\n");
            free(str1);
            free(string);
            continue;
        }

		string[strcspn(string, "\n")] = '\0';

        if (!strcmp(string, "STOP"))//�������� �� ����� ���� 
        {
            free(string);
            break;
        }

		while(100*arrSize-strlen(str1)+1<strlen(string)){ //���� ������������ ������ ��� ������ � �������- �������� ������ ������ ��� ������
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
	// ������� ����� ������ base
	char* p = dest;
	while (*p != '\0') { // while (*p++);
		p++;
	}

	// �������� input � ����� base
	while (*source != '\0') {
		*p++ = *source++;
	}

	// ��������� ������� ������ � ����� base
	*p = '\0';
}
