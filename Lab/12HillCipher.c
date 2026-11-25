#include <stdio.h>
#include <string.h>
#include <ctype.h>
int mod(int x){x%=26; return x<0?x+26:x;}
int inv(int a){for(int i=1;i<26;i++) if(mod(a*i)==1)return i; return -1;}
int main(void){
 char s[500],out[500]; int a=9,b=4,c=5,d=7,det=mod(a*d-b*c),di=inv(det),i,j=0,x,y;
 if(di<0){puts("Key matrix is not invertible.");return 1;}
 printf("Plaintext: "); if(!fgets(s,sizeof s,stdin))return 1;
 for(i=0;s[i];i++)if(isalpha((unsigned char)s[i]))out[j++]=(char)('A'+toupper((unsigned char)s[i])-'A');
 if(j%2)out[j++]='X'; out[j]=0;
 printf("Padded plaintext: %s\nCiphertext: ",out);
 for(i=0;i<j;i+=2){x=out[i]-'A';y=out[i+1]-'A';printf("%c%c",'A'+mod(a*x+b*y),'A'+mod(c*x+d*y));}
 printf("\n"); return 0;
}