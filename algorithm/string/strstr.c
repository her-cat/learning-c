#include "stdio.h"
#include "string.h"

int strStr(char* haystack, char* needle) 
{
    if (strlen(needle) == 0) return 0;

    int m = strlen(haystack), n = strlen(needle);

    for (int i = 0; i < m - n; i++)
    {
        int j = 0, k = i;

        for (; j < n && k < m && haystack[k] == needle[j]; j++, k++);

        if (j == m) return i;
    }
    
}

void main() 
{
    printf("%d\r\n", strStr("abcd", "cd"));
}