/*
«адана строка символов.»спользу€ указатели, переписать строку так, чтобы в начале
строки были символы цифр, затем символы букв латинского алфавита, а в самом конце Ц
прочие символы; пор€док следовани€ цифр / букв латинского алфавита / прочих символов
при этом сохранить.
*/

#include <stdio.h>
#include <ctype.h>

int dig(char hf[]) {//сначала цифры переместить, потом буквы
	int i, k, t=0, yes=0;
	
	for (i = 0; i <= strlen(hf); i++) { //определ€ем количество чисел в строке 
		if (isdigit(hf[i])) 
			t++;
	}
	while (yes < t) {
		for (i = 1; i <= strlen(hf); i++) {
			if (isdigit(hf[i])) {
				if (!isdigit(hf[i - 1])) {
					k = hf[i - 1];
					hf[i - 1] = hf[i];
					hf[i] = k;
				}
				else
					yes++;
			}

		}
	}
	return t;
}

void alph(char hf[], int d1) { //передаЄм количество цифр
	int i, k, t = 0, yes = 0;

	for (i = 0; i <= strlen(hf); i++) { //определ€ем количество букв в строке 
		if (isalpha(hf[i])) 
			t++;
	}
	while (yes < t) {
		for (i = d1+1; i <= strlen(hf); i++) {
			if (isalpha(hf[i])) { 
				if (!isalpha(hf[i - 1])) { 
					k = hf[i - 1];
					hf[i - 1] = hf[i];
					hf[i] = k;
				}
				else
					yes++;
			}
		}
	}
}

int main() {
	int d1 = 0;
	char st[BUFSIZ];

	printf("Enter the string: ");
	fgets(st, BUFSIZ, stdin);

	d1=dig(st); 
	alph(st, d1);

	printf("The result is: %s", st);

	return 0;
}
