
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char plain[] = "abcdefghijklmnopqrstuvwxyz";
    char cipher[] = "cipherabdfgjklmnoqstuvwxyz";
    char text[100], result[100];
    int i, j, choice;
    printf("1. Encryption\n");
    printf("2. Decryption\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter the message: ");
    scanf(" %[^\n]", text);
    for (i = 0; text[i] != '\0'; i++)
    {
        char ch = tolower(text[i]);
        if (ch >= 'a' && ch <= 'z')
        {
            if (choice == 1)
            {
                for (j = 0; j < 26; j++)
                {
                    if (ch == plain[j])
                    {
                        result[i] = cipher[j];
                        break;
                    }
                }
            }
            else if (choice == 2)
            {
                for (j = 0; j < 26; j++)
                {
                    if (ch == cipher[j])
                    {
                        result[i] = plain[j];
                        break;
                    }
                }
            }
            else
            {
                printf("Invalid choice!\n");
                return 0;
            }
        }
        else
        {
            result[i] = text[i];
        }
    }
    result[i] = '\0';
    printf("Result: %s\n", result);

    return 0;
}
