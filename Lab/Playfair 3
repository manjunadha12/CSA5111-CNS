#include <stdio.h>
#include <string.h>
#include <ctype.h>
char m[5][5];
int main()
{
    char key[20], s[100], a, b;
    int used[26]={0}, k=0,i,j,r1,c1,r2,c2;
    printf("Enter key: ");
    scanf("%s",key);
    used['J'-'A']=1;
    for(i=0;key[i];i++){
        a=toupper(key[i]);
        if(a=='J') a='I';
        if(!used[a-'A']){
            m[k/5][k%5]=a;
            used[a-'A']=1; k++;
        }
    }
    for(a='A';a<='Z';a++)
        if(!used[a-'A']){
            m[k/5][k%5]=a;
            used[a-'A']=1; k++;
        }
    printf("Enter plaintext: ");
    scanf("%s",s);
    for(i=0;s[i];i++) s[i]=toupper(s[i]);
    if(strlen(s)%2) strcat(s,"X");
    for(i=0;s[i];i+=2){
        a=s[i]; b=s[i+1];
        if(a=='J') a='I';
        if(b=='J') b='I';
        for(r1=0;r1<5;r1++)
            for(c1=0;c1<5;c1++){
                if(m[r1][c1]==a) goto A;
            }
        A:;
        for(r2=0;r2<5;r2++)
            for(c2=0;c2<5;c2++)
                if(m[r2][c2]==b) goto B;
        B:;
        if(r1==r2){
            s[i]=m[r1][(c1+1)%5];
            s[i+1]=m[r2][(c2+1)%5];
        }
        else if(c1==c2){
            s[i]=m[(r1+1)%5][c1];
            s[i+1]=m[(r2+1)%5][c2];
        }
        else{
            s[i]=m[r1][c2];
            s[i+1]=m[r2][c1];
        }
    }
    printf("Cipher: %s",s);
}
