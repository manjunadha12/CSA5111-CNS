#include <stdio.h>
int m(int x){x%=26;return x<0?x+26:x;}
int inv(int a){for(int i=1;i<26;i++)if(m(a*i)==1)return i;return -1;}
int main(void){
 int p1,p2,p3,p4,c1,c2,c3,c4,det,di,k11,k12,k21,k22;
 printf("Enter plaintext pair blocks P1(x,y), P2(x,y) as 8 integers 0-25: ");
 if(scanf("%d%d%d%d",&p1,&p2,&p3,&p4)!=4)return 1;
 printf("Enter matching ciphertext blocks C1(x,y), C2(x,y): ");
 if(scanf("%d%d%d%d",&c1,&c2,&c3,&c4)!=4)return 1;
 det=m(p1*p4-p2*p3);di=inv(det);if(di<0){puts("Plaintext matrix is not invertible mod 26; choose another pair.");return 1;}
 k11=m((c1*p4-c3*p2)*di);k12=m((-c1*p3+c3*p1)*di);
 k21=m((c2*p4-c4*p2)*di);k22=m((-c2*p3+c4*p1)*di);
 printf("Recovered key matrix:\n%d %d\n%d %d\n",k11,k12,k21,k22);return 0;
}