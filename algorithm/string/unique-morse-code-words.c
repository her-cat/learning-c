#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char** uniqueMorseWords;
char * morses[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

char *parse(char *word) 
{
    int len = strlen(word), index = 0;
    char *result = malloc(sizeof(char) * 4 * len + 1);
    
    memset(result, 0, sizeof(char) * 4 * len + 1);

    for (int i = 0; i < len; i++) {
        index += strlen(morses[word[i] - 'a']);
        strcat(result, morses[word[i] - 'a']);
    }

    result[index] = '\0';

    return result;
}

int insert(char * word) 
{
    int i = 0;
    word = parse(word);

    while (uniqueMorseWords[i]) {
        if (strcmp(uniqueMorseWords[i], word) == 0) 
             return -1;
        i++;
    }

    uniqueMorseWords[i] = word;

    return i;
}

int uniqueMorseRepresentations(char ** words, int wordsSize) 
{
    if (wordsSize == 0) return 0;

    int len = 0;
    uniqueMorseWords = malloc(sizeof(char *) * wordsSize);
    memset(uniqueMorseWords, 0, sizeof(char *) * wordsSize);

    for (int i = 0; i < wordsSize; i++)
        if (insert(words[i]) >= 0)
            len++;

    return len;
}

void main() 
{
    // char * words[] = {"gin", "zen", "gig", "msg"};
    char * words[] = {"kyhp","ywhp","cxzb","cdtzb","cnazb"};

    printf("%d \r\n", uniqueMorseRepresentations(words, 4));
}