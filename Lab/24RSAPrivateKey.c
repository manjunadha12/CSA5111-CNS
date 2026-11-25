#include <stdio.h>
long long gcd(long long a,long long b){while(b){long long t=b;b=a%b;a=t;}return a;}
long long egcd(long long a,long long b,long long *x,long long *y){if(!b){*x=1;*y=0;return a;}long long x1,y1,g=egcd(b,a%b,&x1,&y1);*x=y1;*y=x1-(a/b)*y1;return g;}
int main(void){long long n=3599,e=31,p=0,q=0,phi,x,y,d,i;for(i=2;i*i<=n;i++)if(n%i==0){p=i;q=n/i;break;}if(!p)return puts("Factorization failed."),1;phi=(p-1)*(q-1);egcd(e,phi,&x,&y);d=(x%phi+phi)%phi;printf("p=%lld q=%lld\nphi(n)=%lld\nPublic key: (e=%lld,n=%lld)\nPrivate exponent d=%lld\n",p,q,phi,e,n,d);return 0;}