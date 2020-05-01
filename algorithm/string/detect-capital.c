#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define isUpper(c) c >= 65 && c <= 90
#define isLower(c) c >= 97 && c <= 122


int detectCapitalUse(char * word){
    int isUpperWord = 0, firstCharIsUpper = isUpper(word[0]), len = strlen(word);

    if (len == 0) return 0;
    
    for (int i = 1; i < len; i++)
    {
        if (firstCharIsUpper && i == 1 && isUpper(word[i])) {
            // 当第1个字符和第2个字符都是大写时，如果想要单词大小写正确，就必须是全大写的
            isUpperWord = 1;
        } else if (isUpperWord && isLower(word[i])) {
            // 如果是全大写的单词且当前的字符是小写，说明单词大小写使用错误
            return 0;
        } else if (!firstCharIsUpper && isUpper(word[i])) {
            // 如果首字母不是大写，后面的字符有大写，说明单词大小写使用错误
            return 0;
        } else if (firstCharIsUpper && !isUpperWord && isUpper(word[i])) {
            // 如果仅首字母大写且当前字符是大写，说明单词大小写使用错误
            return 0;
        }
    }
    
    return 1;
}

void main() 
{
    printf("%d \r\n", detectCapitalUse("FlaG"));
}
