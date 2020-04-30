#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int maxNumberOfBalloons(char * text){
    //            b  a  l  l  o  o  n
    int word[] = {0, 0, 0, 0, 0, 0, 0, '\0'};
    int min = 0, index = 0, len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if (text[i] == 'b') word[0]++;
        else if (text[i] == 'a') word[1]++;
        else if (text[i] == 'l') word[2] > word[3] ? word[3]++ : word[2]++;
        else if (text[i] == 'o') word[4] > word[5] ? word[5]++ : word[4]++;
        else if (text[i] == 'n') word[6]++;
    }

    min = word[0];
    while (++index < 7) {
        if (word[index] < min)
            min = word[index];
    }
    
    return min;
}

void main() 
{
    printf("%d\r\n", maxNumberOfBalloons("loonbalxballpoon"));
}
