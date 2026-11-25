#include <stdio.h>
#include <string.h>
#include <ctype.h>
double score(const char *s){const char *f=" ETAOINSHRDLCUMWFGYPBVKJXQZ";double z=0;int i;for(i=0;s[i];i++)if(isalpha((unsigned char)s[i]))z+=26-(strchr(f,toupper((unsigned char)s[i]))?strchr(f,toupper((unsigned char)s[i]))-f:26);return z;}
int main(void){char c[1000],p[1000];int k,i;printf("Ciphertext: ");fgets(c,sizeof c,stdin);for(k=0;k<26;k++){for(i=0;c[i];i++)p[i]=isalpha((unsigned char)c[i])?(char)('A'+(toupper((unsigned char)c[i])-'A'-k+26)%26):c[i];p[i]=0;printf("Key %2d: %s",k,p);}return 0;}