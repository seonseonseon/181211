#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void count_result_print(int line_count, int word_count, int char_count);

int main(int argc, char* argv[])
{
	//OSParadigmShift.txt를 입력하면 <COUNT RESULT>를 출력

	char* fname = "OSParadigmShift.txt";

	FILE *f = fopen(fname, "r");

	if (argv[1] == fname)
	{
		if (f == NULL)
			printf("file open fail\n");

		char str[999] = { 0 };

		int line_count = 0, word_count = 0, char_count = 0;
		while (fgets(str, 999, f) != NULL)
		{
			printf("%s\n", str);
			line_count++;

			int begin_word = 0;
			for (int i = 0; i < strlen(str); i++)
			{
				if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
					if (begin_word)
					{
						word_count++;
						begin_word = 0;
					}
				}
				else {
					if (!begin_word)
						begin_word = 1;
				}
			}

			int i = 0;
			while (*(str + i) != NULL)
			{
				if (*(str + i) == ' ')
					char_count--;
				char_count++;
				i++;
			}
		}
		count_result_print(line_count, word_count, char_count);
	}

	FILE* f_rev = fopen("QSParadigmShift.rev", "w");
	char str[999] = { 0 };

	while (fgets(str, 999, f) != NULL)
	{
		
		for (int i = 0; i < strlen(str); i++)
		{
			if(*(str + i) >= 65 && *(str + i) <= 90)
				fputc(*(str + i) + 32, f_rev);
			else if(*(str + i) >= 97 && *(str + i) <= 122)
				fputc(*(str + i) - 32, f_rev);
			else
				fputc(*(str + i), f_rev);
		}
		
	}

	fclose(f);
	fclose(f_rev);

	printf("File saved in OSParadigmShift.rev\n");
}

void count_result_print(int line_count, int word_count, int char_count)
{
	printf("OSParadigmShift.txt\n");
	printf("<Count Resort>\n");
	printf("Line count : %d\n", line_count);
	printf("Word count : %d\n", word_count);
	printf("Character count : %d\n", char_count);

	return;
}