#include <stdio.h>
#include <ctype.h>
int main(void){char s[1000],p[1000];int k,i;printf("Enter additive cipher text: ");fgets(s,sizeof s,stdin);for(k=0;k<26;k++){for(i=0;s[i];i++)p[i]=isalpha((unsigned char)s[i])?'A'+(toupper((unsigned char)s[i])-'A'-k+26)%26:s[i];p[i]=0;printf("Shift %2d: %s",k,p);}return 0;}