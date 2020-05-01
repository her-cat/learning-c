#include "stdio.h"
#include "string.h"
#include "stdlib.h"

// 记录 magazine 中已被使用的字符
static int * used;

int canConstruct(char * ransomNote, char * magazine){
    int m = strlen(ransomNote), n = strlen(magazine);

    if (m == 0 && n == 0) return 1;
    else if (m == 0 && n > 0 ) return 1;
    else if (m > n) return 0;

    used = malloc(sizeof(int) * n);

    for (int i = 0; i < m; i++)
    {
        int exists = 0;
        for (int j = 0; j < n; j++)
        {
            if (used[j] == 1) continue;

            if (ransomNote[i] != magazine[j]) continue;

            exists = 1;
            used[j] = 1;
            break;
        }

        if (!exists) return 0;
    }

    return 1;
}

void main() 
{
    printf("%d \r\n", canConstruct("aa", "aab"));
}
