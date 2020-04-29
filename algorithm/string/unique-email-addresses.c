#include "stdio.h"
#include "string.h"
#include "stdlib.h"

static char** uniqueEmails;

int indexOf(char* haystack, char needle) 
{
    int len = strlen(haystack);

    if (len == 0) return -1;

    for (int i = 0; i < len; i++)
    {
        if (haystack[i] == needle) {
            return i;
        }
    }

    return -1;
}

char * parse(char * email)
{
    int index = 0, isDomain = 0, len = strlen(email), delimeterIndex = indexOf(email, '@');
    char * result = malloc(sizeof(char) * len+1);

    memset(result, 0, sizeof(char) * len+1);

    for (int i = 0; i < len; i++)
    {
        if (email[i] == '@') {
            isDomain = 1;
        }

        if (isDomain == 1) {
            result[index++] = email[i];
            continue;
        } else if (email[i] == '.') {
            continue;
        } else if (email[i] == '+') {
            i = delimeterIndex-1;
            continue;
        }

        result[index++] = email[i];
    }
    
    result[index] = '\0';

    return result;
}

int insert(char * email) 
{
    int i = 0;

    while (uniqueEmails[i]) {
        if (strcmp(uniqueEmails[i], email) == 0) {
            return -1;
        }
        i++;
    }

    uniqueEmails[i] = email;

    return i;
}

int numUniqueEmails(char ** emails, int emailsSize)
{
    int len = 0;
    if (emailsSize == 0) return 0;

    uniqueEmails = malloc(sizeof(char *) * emailsSize);
    memset(uniqueEmails, 0, sizeof(char *) * emailsSize);

    for (int i = 0; i < emailsSize; i++)
    {
        char * email = parse(emails[i]);
        if (insert(email) >= 0) {
            len++;
        }
    }

    return len;
}

void main() 
{
    char * mails[] = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};

    printf("%d\r\n", numUniqueEmails(mails, 3));
}
