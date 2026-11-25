#include <stdio.h>
int m(int x){x%=26;return x<0?x+26:x;}
int inv(int a){int i;for(i=1;i<26;i++)if(m(a*i)==1)return i;return -1;}
int main(void){int p1,p2,p3,p4,c1,c2,c3,c4,d,di;printf("Chosen plaintext blocks P1(x,y), P2(x,y) (0-25): ");scanf("%d%d%d%d",&p1,&p2,&p3,&p4);printf("Their ciphertext blocks C1(x,y), C2(x,y): ");scanf("%d%d%d%d",&c1,&c2,&c3,&c4);d=m(p1*p4-p2*p3);di=inv(d);if(di<0)return puts("Chosen plaintext matrix is not invertible modulo 26."),1;printf("Recovered key:\n%d %d\n%d %d\n",m((c1*p4-c3*p2)*di),m((-c1*p3+c3*p1)*di),m((c2*p4-c4*p2)*di),m((-c2*p3+c4*p1)*di));return 0;}