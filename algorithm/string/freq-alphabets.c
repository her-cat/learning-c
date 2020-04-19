#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isNumeric(char c)
{
    return c >= 48 && c <= 57;
}

char * freqAlphabets(char * s) 
{
    int len = strlen(s), resultLen = sizeof(char) * len, index = 0;
    char *result = (char *)malloc(resultLen + 1);
    memset(result, 0, resultLen + 1);

    for (int i = 0; i < len; i++)
    {
        if (i + 2 < len && isNumeric(s[i+1]) && s[i+2] == '#') {
            char temp[] = {s[i], s[i+1], '\0'};
            int num = atoi(temp);
            if (num >= 10 && num <= 26) {
                result[index] = num + 96;
                i += 2;
            }
        } else {
            result[index] = s[i] + 48;
        }

        index++;
    }

    result[index] = '\0';

    return result;
}

void main()
{
    printf("%s \r\n", freqAlphabets("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"));
}