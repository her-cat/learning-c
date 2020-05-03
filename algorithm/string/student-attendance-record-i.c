#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int checkRecord(char * s){
    int a = 0, l = 0, len = strlen(s);
    char prev;

    for (int i = 0; i < len; i++)
    {
        if (prev != 'L') l = 0;

        if (s[i] == 'A') a++;
        else if (s[i] == 'L') l++;

        if (a > 1 || l > 2) return 0;

        prev = s[i];
    }
    
    return 1;
}

void main() 
{
    printf("%d \r\n", checkRecord("ALLAPPL"));
}
