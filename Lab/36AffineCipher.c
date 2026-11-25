#include <stdio.h>
#include <ctype.h>
int m(int x){x%=26;return x<0?x+26:x;}
int gcd(int a,int b){while(b){int t=b;b=a%b;a=t;}return a;}
int inv(int a){int i;for(i=1;i<26;i++)if(m(a*i)==1)return i;return -1;}
int main(void){char s[500],mode;int a,b,i,iv;printf("Enter text: ");fgets(s,sizeof s,stdin);printf("Enter a and b: ");scanf("%d%d",&a,&b);a=m(a);b=m(b);if(gcd(a,26)!=1)return puts("Invalid a: gcd(a,26) must be 1."),1;printf("Encrypt or decrypt (e/d): ");scanf(" %c",&mode);iv=inv(a);for(i=0;s[i];i++)if(isalpha((unsigned char)s[i])){int x=toupper((unsigned char)s[i])-'A';putchar('A'+(mode=='e'?m(a*x+b):m(iv*(x-b))));}else putchar(s[i]);return 0;}