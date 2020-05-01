#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char* replaceSpaces(char* S, int length){
    int index = 0;
    char * result = malloc(sizeof(char) * length * 3 + 1);
    memset(result, 0, sizeof(char) * length * 3 + 1);

    for (int i = 0; i < length; i++)
    {
        if (S[i] == ' ') {
            result[index++] = '%';
            result[index++] = '2';
            result[index++] = '0';
            continue;
        }

        result[index++] = S[i];
    }
    
    result[index] = '\0';

    return result;
}

void main() 
{
    printf("%s \r\n", replaceSpaces("Mr John Smith    ", 13));
}