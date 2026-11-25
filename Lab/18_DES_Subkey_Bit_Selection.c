#include <stdio.h>
#include <stdint.h>
static const int P[56]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
int main(void){unsigned long long k;int c=0,d=0,i;printf("Enter 64-bit key in hex: ");if(scanf("%llx",&k)!=1)return 1;for(i=0;i<28;i++){c=(c<<1)|((k>>(64-P[i]))&1);d=(d<<1)|((k>>(64-P[i+28]))&1);}printf("C0 (28 bits) = %07X\nD0 (28 bits) = %07X\n",c,d);puts("The 48-bit DES round subkey is selected from rotated C and D halves: 24 bits from C and 24 bits from D.");return 0;}