#include "stdio.h"
#include "string.h"

// 暴力解法
int strStr(char * haystack, char * needle) {
    int startIndex = 0, haystackIndex = 0, j = 0, 
        haystackLen = strlen(haystack), needleLen = strlen(needle);

    if (needleLen == 0) {
        return 0;
    }

    for (int i = 0; i < haystackLen; i++) {
        if (haystack[i] == needle[0]) {
            j = 1;
            startIndex = i;
            haystackIndex = i;
            for (; j < needleLen; j++) {
                if (haystack[++i] != needle[j]) {
                    i = haystackIndex;
                    startIndex = 0;
                    break;
                }
            }

            if (j == needleLen) {
                return startIndex;
            }
        }
    }

    return -1;
}

void main() {
    printf("%d\r\n", strStr("hello", "ll"));
}
