#include <stdio.h>
#include <string.h>

int main()
{
	char *sentence = "This is target string";
	char word[256] = {0,};
	char *ptr = NULL;

	printf("Input word : ");
	scanf("%s", word);

	ptr = strstr(sentence, word);
	if(ptr != NULL)
	{
		printf("[%s] is exist in [%s]\n", word, sentence);
	}
	else
	{
		printf("[%s] is not exist in [%s]\n", word, sentence);
	}

	return 0;
}
