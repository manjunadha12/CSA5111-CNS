#include <stdio.h>
int main()
{
    char s[100], key[]="QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;
    printf("Enter text: ");
    fgets(s,100,stdin);
    for(i=0;s[i];i++)
        if(s[i]>='A'&&s[i]<='Z')
            s[i]=key[s[i]-'A'];
        else if(s[i]>='a'&&s[i]<='z')
            s[i]=key[s[i]-'a']+32;
    printf("Cipher: %s",s);
}
