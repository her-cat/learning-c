#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int balancedStringSplit(char * s){
    int cnt = 0, balance = 0, len = strlen(s);

    if (len == 0) return 0;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'L') balance--;
        else if (s[i] == 'R') balance++;
        if (balance == 0) cnt++;
    }
    
    return cnt;
}

void main()
{
    printf("%d \r\n", balancedStringSplit("LLLLRRRR"));
}
