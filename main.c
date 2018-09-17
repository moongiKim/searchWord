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

int searchWordInFile(char *fileName, char *word)
{
    int line = 0, count = 0;
    char buffer[256] = {0, }, *ptr = NULL;
    FILE *sfp = NULL;

    sfp = fopen(fileName, "r");
    if (sfp == NULL)
    {
        perror("fopen 실패");
        return -1;
    }

    while (!feof(sfp)) //원본 파일 스트림이 EOF를 만나지 않았다면 반복
    {
		memset(buffer, 0, sizeof(buffer));
		fgets( buffer, sizeof(buffer), sfp);
		line++;
		ptr = mystrstr(buffer, word);
		if(ptr != NULL)
		{
			count++;
			printf("find line [%d]\n", line);
		}
    }

    //파일 스트림 닫기
    fclose(sfp);

    return count;
}

int main()
{
	int status = 0;
	char word[256] = {0,}, fileName[256] = {0,};

	printf("Input FileName : ");
	scanf("%s", fileName);

	status = isExistFile(fileName);
	if(status < 0)
	{
		return status;
	}

	printf("Input word : ");
	scanf("%s", word);

	if(!searchWordInFile(fileName, word))
	{
		printf("Not exist Word\n");
	}

	return 0;
}
