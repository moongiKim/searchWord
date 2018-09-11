#include <stdio.h>
#include <string.h>

char *mystrstr(char *haystack, const char *needle)
{
	int i = 0, j = 0, needleLen = strlen(needle);

	for(; haystack[i] != '\0'; i++)
	{
		if(haystack[i] == needle[0])
		{
			for(j=0 ; needle[j]; j++)
			{
				if(haystack[i+j] != needle[j])
				{
					break;
				}
			}

			if(j == needleLen)
			{
				return haystack+i+j-needleLen;
			}
		}
	}

	return NULL;
}

int main()
{
	char *sentence = "This is target string";
	char word[256] = {0,};
	char *ptr = NULL;

	printf("Input word : ");
	scanf("%s", word);

	ptr = mystrstr(sentence, word);
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
