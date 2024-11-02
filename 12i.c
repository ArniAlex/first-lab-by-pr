//12.����������� ������� ������ ��������� � ������, ����������� ����������� ������� strstr.

#include <stdio.h>

char *strstr2(const char* haystack, const char* needle) {
	int i = strlen(haystack), y = strlen(needle);
	int k, l, o=0, q=-1; 

	for (k = 0; k <= i - y; k++) {
		if (haystack[k] == needle[0]) {//���� ��������� � ������ ��������� ������� ������ - ��������� ������ � ��������� ������
			o = k;
			for (l = 1; l < y ; l++) {
				if (haystack[k + l] != needle[l]) {
					break;
				}
			}
			if (l == y) { // ���������, ��� ��� ������� needle �������
				q = o;
				break;
			}
		}
	}
	if (q == -1) {
		printf("The string was not found\n");
		return NULL;
	}
	else
		return &haystack[q];
}

int main() {
	char str1[] = "Hello";
	char str2[] = "ello";
	
	char *res= strstr2(str1, str2); 

	printf("%s", res);
}