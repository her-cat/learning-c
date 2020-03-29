#include "stdio.h"
#include "string.h"


char romanKeys[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int romanValues[7] = {1, 5, 10, 50, 100, 500, 1000};
char* specialKeys[6]  = {"IV", "IX", "XL", "XC", "CD", "CM"};
int specilaValues[6] = {4, 9, 40, 90, 400, 900};

int getValue(char c) {
    for (int i = 0; i < 7; i++)
    {
        if (romanKeys[i] == c) {
            return romanValues[i];
        }
    }
    return -1;
}

int getSpecialValue(char left, char right) 
{
    char key[3] = {left, right, '\0'};
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(specialKeys[i], key) == 0) {
            // return getValue(right) - getValue(left);
            return specilaValues[i];
        }
    }
    
    return -1;
}

int romanToInt(char * s){
    int num = 0, value = 0, len = strlen(s);

    for (int i = 0; i <= len; i++)
    {
        value = 0;
        if (i + 1 < len) {
            value = getSpecialValue(s[i], s[i+1]);
        }

        if (value > 0) {
            i++;
            num += value;
            continue;
        }
        
        value = getValue(s[i]);
        if (value > 0) {
            num += value;
        }
    }
    return num;
}

int romanToInt2(char* s) {
    int len = strlen(s), num = getValue(s[len-1]);

    for (int i = len-2; i >= 0; i--)
    {
        int cur = getValue(s[i]);
        int right = getValue(s[i+1]);
        if (cur < right)
            num -= cur;
        else
            num += cur;
    }

    return num;
}

void main() {
    printf("%d\r\n", romanToInt("DCXXI"));
}
