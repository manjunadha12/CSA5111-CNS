#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[100], key[100];
    int i, k, j;
    printf("Enter text: ");
    scanf("%s", s);
    printf("Enter key: ");
    scanf("%s", key);
    j = strlen(key);
    for(i = 0; s[i] != '\0'; i++)
    {
        s[i] = toupper(s[i]);
        key[i % j] = toupper(key[i % j]);
        k = key[i % j] - 'A';
        s[i] = (s[i] - 'A' + k) % 26 + 'A';
    }
    printf("Cipher text: %s", s);
    return 0;
}
