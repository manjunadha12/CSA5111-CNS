#include <stdio.h>
#include <stdint.h>
static const int PC1[56]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
static const int PC2[48]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
static const int sh[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
int bit(uint64_t x,int p,int n){return (int)((x>>(n-p))&1);}
int main(void){unsigned long long key;int c=0,d=0,i,r,s;unsigned long long cd,sub;printf("Enter 64-bit DES key in hexadecimal (16 hex digits): ");if(scanf("%llx",&key)!=1)return 1;for(i=0;i<28;i++){c=(c<<1)|bit(key,PC1[i],64);d=(d<<1)|bit(key,PC1[i+28],64);}int C[17],D[17];C[0]=c;D[0]=d;for(r=1;r<=16;r++){s=sh[r-1];C[r]=((C[r-1]<<s)|(C[r-1]>>(28-s)))&0xfffffff;D[r]=((D[r-1]<<s)|(D[r-1]>>(28-s)))&0xfffffff;}puts("Decryption round keys (K16 to K1):");for(r=16;r>=1;r--){cd=((unsigned long long)C[r]<<28)|D[r];sub=0;for(i=0;i<48;i++)sub=(sub<<1)|((cd>>(56-PC2[i]))&1);printf("K%d = %012llX\n",r,sub);}return 0;}