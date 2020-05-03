#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int countSegments(char * s){
    int cnt = 0, len = strlen(s);

    for (int i = 0; i < len; i++)
        if (s[i] != ' ' && (i + 1 == len || s[i + 1] == ' '))
            cnt++;
    
    return cnt;
}

void main() 
{
    printf("%d \r\n", countSegments("Hello, my name is John"));
}
