#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINTPOLISH 0
#define PRINTNORMAL 1
#define EVALUATE 2
#define HEIGHT 3
#define LEAFS 4
#define EQUALITY 5

int functionToCode(char* word)
{
	if (strcmp(word, "print_polish") == 0)
		return PRINTPOLISH;
	if (strcmp(word, "print_normal") == 0)
		return PRINTNORMAL;
	if (strcmp(word, "evaluate") == 0)
		return EVALUATE;
	if (strcmp(word, "height") == 0)
		return HEIGHT;
	if (strcmp(word, "leafs") == 0)
		return LEAFS;
	if (strcmp(word, "equality") == 0)
		return EQUALITY;
	return -1;
}

int numberOfLines(const char* filename)
{
	FILE* fin = fopen(filename, "r");
	if (fin == NULL) {
		fprintf(stderr, "ERROR openning file \"%s\".\n", filename);
		exit(8402);
	}
	char character;
	int counter = 1;
	while (!feof(fin)) {
		fscanf(fin, "%c", &character);
		if (character == '\n')
			counter++;
	}
	fclose(fin);
	return counter;
}

typedef struct node {
	char value;
	struct node* childLeft;
	struct node* childRight;
} node;

node* readTree(FILE* f)
{
	char aux;
	if (feof(f))
		return NULL;
	fscanf(f, "%c", &aux);
	if (aux == ' ')
		return readTree(f);
	node* expression = (node*)malloc(sizeof(node));
	if (expression == NULL)
		return NULL;
	expression->value = aux;
	if (aux == '+' || aux == '-' || aux == '*' || aux == '/') {
		//TODO trebuie completat resul nodului expression.
		//     aici va fi macar un apel recursiv
	} else {
		//TODO
	}
	return expression;
}

node* readTreeFromFile(const char* fileName)
{
	FILE* f = fopen(fileName, "r");
	if (f == NULL)
		return NULL;
	node* expression = readTree(f);
	fclose(f);
	return expression;
}

void printPolish(node* expresion)
{
	// TO DO
}

void printNormal(node* expresion)
{
	// TO DO
}

int evaluate(node* expression)
{
	// TO DO
	return 0;
}

int getHight(node* expression)
{
	// TO DO
	return 0;
}

int getLeafs(node* expression)
{
	// TO DO
	return 0;
}

int areEqual(node* a, node* b)
{
	// TO DO
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc > 1) {
		FILE* f = fopen(argv[1], "r");
		char word[256];
		node* expressions[3];
		char files[5][100];
		int cnt = 0;
		while (!feof(f)) {
			if (cnt > 2) {
				break;
			}
			fscanf(f, "%s", word);
			strcpy(files[cnt], word);
			// ex0
			expressions[cnt++] = readTreeFromFile(word);
		}
		fclose(f);
		node* expression1 = expressions[0];
		node* expression2 = expressions[1];
		node* expression3 = expressions[2];
		int numberOfCalls = numberOfLines("generatedMain");
		FILE* fin = fopen("generatedMain", "r");
		if (fin == NULL) {
			fprintf(stderr, "ERROR openning file \"generatedMain\".\n");
			exit(8402);
		}
		for (int i = 0; i < numberOfCalls; i++) {
			char function[50];
			fscanf(fin, "%s", function);
			int code = functionToCode(function);
			switch (code) {
			case PRINTPOLISH:
				printPolish(expression1);
				break;
			case PRINTNORMAL:
				printNormal(expression1);
				break;
			case EVALUATE:
				printf("%d", evaluate(expression1));
				break;
			case HEIGHT:
				printf("%d", getHight(expression1));
				break;
			case LEAFS:
				printf("%d", getLeafs(expression1));
				break;
			case EQUALITY:
				// testeaza in urmatoarea ordine:
				// exp1 cu exp2, exp2 cu exp3, exp3 cu exp1

				if (areEqual(expression1, expression2))
					printf("Arborele din %s este identic cu cel din %s", files[0], files[1]);
				else
					printf("Arborele din %s este DIFERIT de cel din %s", files[0], files[1]);

				if (areEqual(expression2, expression3))
					printf("Arborele din %s este identic cu cel din %s", files[1], files[2]);
				else
					printf("Arborele din %s este DIFERIT de cel din %s", files[1], files[2]);

				if (areEqual(expression3, expression1))
					printf("Arborele din %s este identic cu cel din %s", files[2], files[0]);
				else
					printf("Arborele din %s este DIFERIT de cel din %s", files[2], files[0]);

				break;

			default:
				break;
			}
			if ((i + 1) != numberOfCalls)
				printf("\n");
		}
	} else {
		printf("No parameters sent!");
	}
	return 0;
}