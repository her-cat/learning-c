#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverseLeftWords(char* s, int n) 
{
    int index = 0, len = strlen(s), resultLen = sizeof(char*) * len;
    char *temp = malloc(resultLen+1);
    memset(temp, 0, resultLen+1);

    for (int i = 0; i < n; i++)
    {
        temp[len-n+i] = s[i];
    }

    for (int i = n; i < len; i++)
    {
        temp[i-n] = s[i];
    }
    
    return temp;
}

void main()
{
    printf("%s \r\n", reverseLeftWords("abcdefg", 2));
}