#include <stdio.h>
#include <string.h>
#include <unistd.h>

int isExistFile(char *fileName)
{
	if (0 == access(fileName, F_OK))
	{
		printf("exist file [%s]\n", fileName);

		if ( 0 != access(fileName, R_OK) )
		{
			printf("Don't read file [%s]\n", fileName);
			return -1;
		}
	}
	else
	{
		printf("Not exist file [%s]\n", fileName);
		return -2;
	}

	return 0;
}

char *mystrstr(char *haystack, const char *needle)
{
	int i = 0, j = 0, needleLen = 0;

	if(haystack == NULL || needle == NULL)
		return NULL;

	needleLen = strlen(needle);

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
	int status = 0;
	char *sentence = "This is target string";
	char word[256] = {0,}, fileName[256] = {0,};
	char *ptr = NULL;

	printf("Input FileName : ");
	scanf("%s", fileName);

	status = isExistFile(fileName);
	if(status < 0)
	{
		return status;
	}
/*
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
*/
	return 0;
}
