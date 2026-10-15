#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[100];
    int a, b, i;
    printf("Enter text: ");
    scanf("%s", s);
    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);
    for(i = 0; s[i] != '\0'; i++)
    {
        s[i] = toupper(s[i]);
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = ((a * (s[i] - 'A') + b) % 26) + 'A';
    }
    printf("Cipher text: %s", s);
    return 0;
}
