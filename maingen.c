#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PRINTPOLISH 0
#define PRINTNORMAL 1
#define EVALUATE 2
#define HEIGHT 3
#define LEAFS 4
#define EQUALITY 5

char* codeToFunction(int number)
{
	char* word = NULL;
	switch (number) {
	case PRINTPOLISH:
		word = (char*)malloc(strlen("print_polish") + 1);
		strcpy(word, "print_polish");
		return word;
	case PRINTNORMAL:
		word = (char*)malloc(strlen("print_normal") + 1);
		strcpy(word, "print_normal");
		return word;
	case EVALUATE:
		word = (char*)malloc(strlen("evaluate") + 1);
		strcpy(word, "evaluate");
		return word;
	case HEIGHT:
		word = (char*)malloc(strlen("height") + 1);
		strcpy(word, "height");
		return word;
	case LEAFS:
		word = (char*)malloc(strlen("leafs") + 1);
		strcpy(word, "leafs");
		return word;
	case EQUALITY:
		word = (char*)malloc(strlen("equality") + 1);
		strcpy(word, "equality");
		return word;
	default:
		return word;
	}
}

int main(int argc, char* argv[])
{
	FILE* f = fopen("generatedMain", "w");
	if (f == NULL) {
		fprintf(stderr, "ERROR openning file \"%s\".", argv[1]);
		exit(8402);
	}
	srand(time(NULL));
	int tests = 10 + rand() % 11;
	for (int i = 0; i < tests; i++) {
		int functionCode = rand() % 6;
		char* function = codeToFunction(functionCode);
		if (function != NULL) {
			fprintf(f, "%s", function);
			free(function);
		}
		if (i != tests - 1) {
			fprintf(f, "\n");
		}
	}
	fclose(f);
	return 0;
}