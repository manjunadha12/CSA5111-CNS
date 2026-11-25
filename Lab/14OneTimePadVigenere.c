#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
 char s[300];int k[300],n=0,i,j=0,v;
 printf("Enter plaintext: ");fgets(s,sizeof s,stdin);
 printf("Enter key stream length (letters only): ");scanf("%d",&n);
 if(n<=0||n>250)return puts("Invalid length."),1;
 printf("Enter %d key numbers (0-25): ",n);
 for(i=0;i<n;i++)if(scanf("%d",&k[i])!=1||k[i]<0||k[i]>25)return puts("Invalid key."),1;
 printf("Ciphertext: ");
 for(i=0;s[i];i++)if(isalpha((unsigned char)s[i])){if(j>=n)return puts("\nKey stream too short."),1;v=toupper((unsigned char)s[i])-'A';putchar('A'+(v+k[j++])%26);}else putchar(s[i]);
 puts("");return 0;
}