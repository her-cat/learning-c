#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char data[1000];
int top = 0;

void push(char value)
{
    if (top == 999) return;

    data[top++] = value;
}

char pop()
{
    if (top == 0) return '\0';

    return data[--top];
}

char * reverseWords(char * s)
{
    char value;
    int len = strlen(s), index = 0;

    char *word = malloc(sizeof(char) * len + 2);
    assert(word != NULL);
    memset(word, 0, sizeof(char) * len + 2);

    for (int i = 0; i < len; i++) {
        push(s[i]);

        if (s[i] != ' ' && i + 1 != len) {
            continue;
        } else if (i + 1 == len && index != 0) {
            // 处理最后一个单词
            word[index++] = ' ';
        }

        while (value = pop()) {
            if (index == 0 && value == ' ') continue;
            word[index++] = value;
        }
    }

    return word;
}

void main()
{
    printf("%s \r\n", reverseWords("Let's take LeetCode contest"));
}