#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int judgeCircle(char * moves){
    int x = 0, y = 0, len = strlen(moves);

    if (len == 0) return 0;
    if (len % 2 != 0) return 0;

    for (int i = 0; i < len; i++)
    {
        if (moves[i] == 'U') x++;
        else if (moves[i] == 'D') x--;
        else if (moves[i] == 'L') y--;
        else if (moves[i] == 'R') y++;
    }
    
    return x == 0 && y == 0;
}

void main()
{
    printf("%d \r\n", judgeCircle("UD"));
}