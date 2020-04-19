#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * defangIPaddr(char * address){
    int index = 0, len = strlen(address), resultLen = sizeof(char *) * len + 7;

    char * result = malloc(resultLen);

    memset(result, 0, resultLen);

    for (int i = 0; i < len; i++)
    {
        if (address[i] == '.') {
            result[index++] = '[';
            result[index++] = '.';
            result[index++] = ']';
        } else {
            result[index++] = address[i];
        }
    }

    result[resultLen-1] = '\0';
    
    return result;
}

void main()
{
    printf("%s \r\n", defangIPaddr("1.1.1.1"));
}